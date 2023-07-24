class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        vector<int> xorvec(n,0);
        int xorVal=0;
        for(int i=0;i<n;i++){
            xorVal^=nums[i];
            xorvec[i]=xorVal;
        }
        int j=0;
        reverse(xorvec.begin(),xorvec.end());
        int temp=1<<maximumBit;
        int maxK=temp-1;
        for(int i=0;i<n;i++){
            xorvec[i]=xorvec[i]^maxK;
        }
        return xorvec;
    }
};