class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k){return false;}
        map<int,int> mp;
        int mx=INT_MIN;
        for(auto i:nums){
            mp[i]++;
            mx=max(mx,i);
        }
        int cnt=0;
        int i=1;
        auto it=mp.begin();
        while(it!=mp.end()){
            if(it->second){
                it->second--;
                int k1=1;
                while(k1<k){
                    if(!mp[it->first+k1]){return false;}
                    mp[it->first+k1]--;
                    k1++;
                }
                cnt+=k;
            }
            if(!it->second){it++;}
        }
        if(cnt!=nums.size()){return false;}
        return true;
    }
};