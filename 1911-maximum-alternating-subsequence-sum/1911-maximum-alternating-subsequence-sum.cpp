class Solution {
public:
    // int slv(int ind,int j,int diff,vector<int> &nums,vector<vector<int>> &dp){
    //     if(ind==nums.size()-1){
    //         int diffNew=0;
    //         if(j==0){
    //             diffNew=diff+nums[ind];
    //         }
    //         else{
    //             diffNew=diff-nums[ind];
    //         }
    //         return dp[ind][j]=max(diffNew,diff);
    //     }
    //     if(dp[ind][j]!=-1){return dp[ind][j];}
        
    //     int take=0;
    //     int diffNew=0;
    //     if(j==0){
    //         diffNew=diff+nums[ind];
    //         take=slv(ind+1,1,diffNew,nums,dp);
    //     }
    //     else{
    //         diffNew=diff-nums[ind];
    //         take=slv(ind+1,0,diffNew,nums,dp);
    //     }
    //     //int take=slv(ind+1,1,diffNew,nums,dp);
    //     int notTake=slv(ind+1,j,diff,nums,dp);
    //     return dp[ind][j]=max(notTake,take);
    // }
    long long slv(int ind,int type,vector<vector<long long>> &dp,vector<int> &nums){
        if(ind==nums.size()){return 0;}
        if(dp[ind][type]!=-1){return dp[ind][type];}
        long long take=0;
        if(type==0){
            take=nums[ind]+slv(ind+1,1,dp,nums);
        }
        else{
            take=-nums[ind]+slv(ind+1,0,dp,nums);
        }
        long long notTake=slv(ind+1,type,dp,nums);
        return dp[ind][type]=max(take,notTake);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>> dp(n,vector<long long>(2,-1));
        return slv(0,0,dp,nums);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // return ans;
        // return slv(0,0,0,nums,dp);
    }
};