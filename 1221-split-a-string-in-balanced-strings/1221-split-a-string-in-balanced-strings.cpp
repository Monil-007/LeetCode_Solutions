class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0,countL=0,countR=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='R')
                countR++;
            else
                countL++;
            if(countR==countL){
                count++;
            }
        }
        return count;
    }
};