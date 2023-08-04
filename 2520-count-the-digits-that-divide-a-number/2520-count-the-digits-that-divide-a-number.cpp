class Solution {
public:
    int countDigits(int num) {
        int cnt=0;
        string s=to_string(num);
        for(auto i:s){
            int x=i-'0';
            if(num%x==0){cnt++;}
        }
        return cnt;
    }
};