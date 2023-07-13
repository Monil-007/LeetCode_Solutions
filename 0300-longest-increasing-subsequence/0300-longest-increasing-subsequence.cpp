class Solution {
public:
    int slv(int ind,int lastInd,vector<int> &nums,vector<vector<int>> &dp){
        if(ind==nums.size()){return 0;}
        if(dp[ind][lastInd+1]!=-1){return dp[ind][lastInd+1];}
        int take=0;
        if(lastInd==-1 || nums[ind]>nums[lastInd]){
            take=1+slv(ind+1,ind,nums,dp);
        }
        int notTake=slv(ind+1,lastInd,nums,dp);
        
        return dp[ind][lastInd+1]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        //return slv(0,-1,nums,dp);
    
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int notTake=dp[i+1][j+1];
                int take=0;
                if(j==-1 || nums[i]>nums[j]){
                    take=1+dp[i+1][i+1];
                }
                dp[i][j+1]=max(notTake,take);
            }
        }
        return dp[0][0];
    }
};