class Solution {
public:
    int mostWordsFound(vector<string>& s) {
        int mx=0;
        for(auto i:s){
            int cnt=0,j;
            for(j=0;j<i.size();j++){
                if(i[j]==' '){cnt++;}
            }
            if(i[j-1]!=' '){cnt++;}
            mx=max(mx,cnt);
        }
        return mx;
    }
};