class Solution {
public:
    string reversePrefix(string word, char ch) {
        int s = 0;
        int e = 0;
        for(int i=0;i<word.size();i++){
            if(ch==word[i]){
                e = i;
                break;
            }
        }
        while(s<e){
            swap(word[s++],word[e--]);
        }
        return word;
    }
};
