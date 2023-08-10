class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        vector<int> pref(nums.size());
        vector<int> suff(nums.size());
        int sum=0;
        for(int i=0;i<nums.size();i++){
            pref[i]=sum;
            sum+=nums[i];
        }
        sum=0;
        int midIn=-1;
        for(int j=nums.size()-1;j>=0;j--){
            suff[j]=sum;
            sum+=nums[j];
            if(suff[j]==pref[j]){midIn=j;}
        }
        return midIn;
    }
};