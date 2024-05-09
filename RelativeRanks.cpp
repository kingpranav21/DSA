class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        priority_queue<pair<int,int>>max_heap;
        for(int i=0;i<n;i++){
            max_heap.push({score[i],i});
        }

        vector<string>ans(n);
        int place = 1;
        while(!max_heap.empty()){
            int idx = max_heap.top().second;
            max_heap.pop();
            if(place==1){
                ans[idx]="Gold Medal";
            }else if(place==2){
                ans[idx]="Silver Medal";
            }else if(place==3){
                ans[idx]="Bronze Medal";
            }else{
                ans[idx]=to_string(place);
            }
            place++;
        }
        return ans;
    }
};
