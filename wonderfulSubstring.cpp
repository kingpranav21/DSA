class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<long long,long long>mp;
        mp[0]=1; //001
        int cum_xor = 0; //past mei 1, had seen curr_xor =0; //cum_xor->cumulative 
        long long res = 0;
        for(char &ch:word){
            //FOR EVEN PART
            //how much is needed to shift to convert char to binary
            int shift = ch -'a';
            //'a'-'a' = 0 , no shift -> 001
            //'b'-'a' = 1 , shift left , 1<<shift, -> 010
            cum_xor = cum_xor ^ (1 << shift);
            //eg for a 
            //in past we have seen value of a, add in res
            // for b
            // 010 , no not seen , push in map first & check for odd
            res+=mp[cum_xor]; //all char which are even in count

            //FOR ODD
            for(char ch1='a';ch1<='j';ch1++){
                shift = ch1-'a';
                long long check_xor = (cum_xor^(1<<shift));
                res+=mp[check_xor];
            }
            mp[cum_xor]++;
        }
        return res;
    }
};
