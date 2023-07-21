class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int countFlips=0,count1s=0,ans=0;
        for(auto i:s){
            if(i=='0'){countFlips++;}
            else{count1s++;}
            countFlips=min(count1s,countFlips);
        }
        return countFlips;
    }
};