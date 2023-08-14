class Solution {
public:
    vector<int> shortestToChar(string s, char c) 
    {
        vector<int> ans(s.size());
        int pos=-s.size();
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==c)
            {
                pos=i;
            }
            ans[i]=i-pos;
        }
        for(int i=pos-1;i>=0;i--)
        {
            if(s[i]==c)
                pos=i;
            ans[i]=min(ans[i],pos-i);
        }
        return ans;
    }
};