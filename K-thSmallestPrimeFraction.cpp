class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<vector<double>>pq; //{fraction, arr[i], arr[j]}
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double fraction = (double)arr[i]/arr[j];
                pq.push({fraction,(double)arr[i],(double)arr[j]});
                if(pq.size()>k){
                  pq.pop();
                }
            }
        }
        auto vec = pq.top();
        vector<int>res(2);
        res[0] = vec[1];
        res[1] = vec[2];
        return res;
    }
};
