class Solution {
public:
    int slv(int i,int j,vector<int> &nums1,vector<int> &nums2,vector<vector<int>> &dp){
        if(i>=nums1.size() || j>=nums2.size()){
            return 0;
        }
        if(dp[i][j]!=-1){return dp[i][j];}
        int notTake=slv(i+1,j,nums1,nums2,dp);
        int take=0;int ind=-1;
        for(int j1=j;j1<nums2.size();j1++){
            if(nums2[j1]==nums1[i]){
                ind=j1;
                break;
            }
        }
        if(ind==-1){
            take=slv(i+1,j,nums1,nums2,dp);
        }
        else{
            take=1+slv(i+1,ind+1,nums1,nums2,dp);
        }
        return dp[i][j]=max(notTake,take);
    }
    int slv2(int i,int j,vector<int> &nums1,vector<int> &nums2,vector<vector<int>> &dp){
        if(i<0 || j<0){return 0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        if(nums1[i]==nums2[j]){
            return dp[i][j]=1+slv2(i-1,j-1,nums1,nums2,dp);
        }
        else{
            return dp[i][j]=max(slv2(i-1,j,nums1,nums2,dp),slv2(i,j-1,nums1,nums2,dp));
        }
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));
       // return slv2(n1-1,n2-1,nums1,nums2,dp);
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(nums1[i-1]==nums2[j-1]){dp[i][j]=1+dp[i-1][j-1];}
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];
        // int j=n2-1;
        // for(int i=n1-1;i>=0;i--){
        //         int notTake=dp[i+1][j];
        //         int take=0;int ind=-1;
        //         for(int j1=j;j1>=0;j1--){
        //             if(nums1[i]==nums2[j1]){
        //                 ind=j1;
        //                 break;
        //             }
        //         }
        //         if(ind==-1){take=dp[i+1][j];}
        //         else{take=1+dp[i+1][ind+1];}
        //         dp[i][j]=max(notTake,take);
        //         j=ind+1;
        // }
        // for(int i=0;i<)
        // return dp[0][0];
    }
};