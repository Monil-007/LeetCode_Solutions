class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.size();
        int cnt=n;
        vector<int> res(n+1);
        for(int i=0;i<n;i++){
            if(s[i]=='D'){res[i]=cnt--;}
        }
        int cn=0;
        for(int i=0;i<n;i++){
            if(s[i]=='I'){res[i]=cn++;}
        }
        res[n]=cn;
        return res;
    }
};