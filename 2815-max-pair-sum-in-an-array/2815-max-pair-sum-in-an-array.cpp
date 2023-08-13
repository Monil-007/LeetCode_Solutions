class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<int> v;
        for(auto i:nums){
            string s=to_string(i);
            int mx=0;
            for(auto j:s){
                int x=j;
                mx=max(mx,x);
            }
            v.push_back(mx);
        }
        int rs=-1;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(v[j]==v[i]){
                    rs=max(rs,nums[i]+nums[j]);
                }
            }
        }
        return rs;
    }
};