// Problem - 834 
// Sum of Distances in a Tree:
// Topic : Graph
// There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.
// You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
// Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes.

//Approach 1
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        //creating graph
        unordered_map<int,vector<int>>adjaceny_list;
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            adjaceny_list[u].push_back(v);
            adjaceny_list[v].push_back(u);
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            dfs(i,0,-1,adjaceny_list,ans);
        }
        return ans;
    }
    void dfs(int curr_node,int dist,int parent,unordered_map<int,vector<int>>&adjaceny_list,vector<int>&ans){
        for(int neighbour: adjaceny_list[curr_node]){
          if(neighbour!=parent){
            dfs(neighbour,dist+1,curr_node,adjaceny_list,ans);
          }
        }
        ans[curr_node]+=dist;
    }
};
//Approach 2
class Solution {
public:

    vector<int>count;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        count.resize(n,0);
        //creating graph
        unordered_map<int,vector<int>>adjaceny_list;
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            adjaceny_list[u].push_back(v);
            adjaceny_list[v].push_back(u);
        }
        long root_res =0;//for storing distances
        //count of subtree nodes including child node
    
        dfs_root(root_res,0,0,-1,adjaceny_list);
        vector<int>res(n,0);
        res[0] = root_res;

        //dfs for further nodes
        DFS(adjaceny_list,0,-1,res,n);

        return res;
    }
    int dfs_root(long &root_result,int curr_node,int curr_dist,int parent,unordered_map<int,vector<int>>&adjaceny_list){
        //for parent
        int total_count=1;
        for(int child: adjaceny_list[curr_node]){
          if(child!=parent){
            total_count+=dfs_root(root_result,child,curr_dist+1,curr_node,adjaceny_list);
          }
        }
        root_result+=curr_dist;

        //curr node count
        count[curr_node]=total_count;

        return total_count;
    }
    void DFS(unordered_map<int,vector<int>>&adj,int parent_node,int prev_node,vector<int>&res,int n){
        for(int &child : adj[parent_node]){
            if(child!=prev_node){
                res[child]=res[parent_node]-count[child]+(n-count[child]);
                DFS(adj,child,parent_node,res,n);
            }
        }
    }
};
