class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people),end(people));
        int s=0;
        int boats = 0;
        int e = people.size()-1;
        while(s<=e){
          if(people[s]+people[e]<=limit){
             s++;
             e--;
          }else{
            e--;
          }
          boats++;
        }
        return boats;
    }
};
