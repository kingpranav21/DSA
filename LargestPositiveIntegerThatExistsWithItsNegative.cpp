class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int maxi =-1;
        unordered_set<int>set;
        for(auto num : nums){
            set.insert(num);
            if(set.find(-num)!=set.end()){
                maxi = max(abs(num),maxi);
            }
        }
        return maxi;
    }
};
