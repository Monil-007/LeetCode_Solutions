class Solution {
public:
    int slv(int ind,int tmr,vector<vector<int>> &mdp,vector<int> &s){
        if(ind>=s.size()){
            return 0;
        }
        if(mdp[ind][tmr]!=-1){return mdp[ind][tmr];}
        int notTake=slv(ind+1,tmr,mdp,s);
        int take=s[ind]*tmr+slv(ind+1,tmr+1,mdp,s);
        return mdp[ind][tmr]=max(notTake,take);

    }
    int maxSatisfaction(vector<int>& s) {
        int n=s.size();
        sort(s.begin(),s.end());
        vector<vector<int>> t(n,vector<int> (n+1,-1));
        return slv(0,1,t,s);
    }
};