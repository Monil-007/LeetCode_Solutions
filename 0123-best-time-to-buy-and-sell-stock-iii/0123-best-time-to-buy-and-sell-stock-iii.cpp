class Solution {
public:
    int slv(int ind,int st,int k,vector<int> &prices,vector<vector<vector<int>>> &mdp){
        if(ind>=prices.size()){
            return 0;
        }
        if(mdp[ind][st][k]!=-1){return mdp[ind][st][k];}
        //if(k==0){return 0;}
        if(st==0){
            //if(k<=0){return }
            int purch=0;
            if(k>=1){
                purch=-prices[ind]+slv(ind+1,1,k-1,prices,mdp);
            }
            return mdp[ind][st][k]=max(purch,slv(ind+1,st,k,prices,mdp));
        }
        else{
            return mdp[ind][st][k]=max(prices[ind]+slv(ind+1,0,k,prices,mdp),slv(ind+1,st,k,prices,mdp));
        }
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> mdp(n,vector<vector<int>> (2,vector<int> (3,-1)));
        return slv(0,0,2,prices,mdp);
    }
};