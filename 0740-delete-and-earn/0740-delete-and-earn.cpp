class Solution {
public:
    int slv(int ind,vector<int> &dp,vector<int> &nums){
        if(ind>=nums.size()){return 0;}
        if(dp[ind]!=-1){return dp[ind];}
        int currValue=nums[ind];
        int index=ind+1;
        int currSum=nums[ind];
        while(index<nums.size() && nums[index]==currValue){
            currSum+=nums[index++];
        }
        while(index<nums.size() && nums[index]==currValue+1){
            index++;
        }
        int take=currSum+slv(index,dp,nums);
        int notTake=slv(ind+1,dp,nums);
        return dp[ind]=max(take,notTake);
    }
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        sort(nums.begin(),nums.end());
        return slv(0,dp,nums);
    }
};