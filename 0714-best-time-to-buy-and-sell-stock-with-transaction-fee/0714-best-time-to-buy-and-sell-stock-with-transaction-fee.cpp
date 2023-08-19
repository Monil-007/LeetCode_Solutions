class Solution {
public:
    int slv(int ind,int fg,int prev,vector<vector<int>> &t,int &fee,vector<int> &prices){
        if(ind>=prices.size()){return 0;}
        if(t[ind][fg]!=-1){return t[ind][fg];}
        if(fg){
            int notSell=slv(ind+1,fg,prev,t,fee,prices);
            int sell=0;
            if(prices[ind]>prices[prev]){
                sell=prices[ind]-prices[prev]-fee+slv(ind+1,0,-1,t,fee,prices);
            }
            return t[ind][fg]=max(notSell,sell);
        }
        else{
            int notBuy=slv(ind+1,fg,prev,t,fee,prices);
            int buy=slv(ind+1,1,ind,t,fee,prices);
            return t[ind][fg]=max(notBuy,buy);
        }
    }

    int find(int ind,vector<int> &v,bool buy,vector<vector<int>> &memo,int fee)
{    
    if(ind>=v.size()) return 0;
    if(memo[ind][buy]!=-1) return memo[ind][buy];
    
    if(buy) 
    {      
       return memo[ind][buy]=max(-v[ind]+find(ind+1,v,!buy,memo,fee),find(ind+1,v,buy,memo,fee));  
    }
    else   
    {      
       return memo[ind][buy]=max(v[ind]-fee+find(ind+1,v,!buy,memo,fee),find(ind+1,v,buy,memo,fee));  
    }
     
}
    int maxProfit(vector<int>& prices, int fee) {
        // int n=prices.size();
        // vector<vector<int>> m(n+1,vector<int> (2,-1));
        // return slv(0,0,-1,m,fee,prices);
        int n=prices.size();
        if(n<2) return 0;
        vector<vector<int>> v(n+1,vector<int>(2,-1));
        //passing here buy=1 because we will first buy then sell 
        return find(0,prices,1,v,fee);
    }
};