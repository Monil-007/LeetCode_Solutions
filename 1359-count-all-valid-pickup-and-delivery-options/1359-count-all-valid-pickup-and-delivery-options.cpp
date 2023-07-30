class Solution {
public:
int mod=1e9+7;
    int countOrders(int n) {
        if(n==1){return 1;}
        if(n==2){return 6;}
        vector<long long> dp(n+1,1);
        dp[2]=6;
       for(int i=3;i<=n;i++){
           long long x=i*(2*i-1)*dp[i-1];
           dp[i]=x%mod;
       } 
       return dp[n];
    }
};