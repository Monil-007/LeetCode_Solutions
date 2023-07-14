class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int j=0;
        bool fg=false,brk=false;
        char curr;
        int mn=INT_MAX;
        for(int i=0;i<strs.size();i++){
            if(strs[i].size()<mn){mn=strs[i].size();}   
        }
        string ans="";
        while(mn--){
            fg=false;brk=false;
        for(int i=0;i<strs.size();i++){
            if(!fg){
                curr=strs[i][j];
                fg=true;
            }
            else{
                if(strs[i][j]!=curr){brk=true;break;}
            }
        }
        if(!brk){
            ans+=strs[0][j];
        }
        else{
            return ans;
        }
        j++;
        }
        return ans;
    }
};