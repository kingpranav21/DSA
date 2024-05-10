//Approach 1
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(begin(happiness),end(happiness),greater<int>());
        long long res =0;
        int cnt =0;
        for(int i=0;i<k;i++){
          res+=max(happiness[i]-cnt,0);
          cnt++;
        }
       return res;
    }
};

//Approach 2
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int>max_heap;
        long long res =0;
        int count =0;
        for(auto happy : happiness){
            max_heap.push(happy);
        }
        for(int i=0;i<k;i++){
            int curr = max_heap.top();
            max_heap.pop();
            res+=max(curr-count,0);
            count++;
        }
        return res;
    }
};
