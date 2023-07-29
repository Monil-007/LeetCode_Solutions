class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> mp;
        string s=to_string(n);
        //mp[n]=1;
        while(1){
            if(s[0]=='1' && s.size()==1){return true;}
            int tmp=0;
            for(auto it:s){
                int x=it-'0';
                tmp+=x*x;
            }
            if(mp[tmp]){return false;}
            mp[tmp]=1;
            s=to_string(tmp);
        }
        return true;
    }
};