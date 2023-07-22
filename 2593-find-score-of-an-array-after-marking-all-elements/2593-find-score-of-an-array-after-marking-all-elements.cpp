class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        //int maxVal=0;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
            //maxVal=max(maxVal,nums[i]);
        }
        vector<int> vis(nums.size(),0);
        long long sum=0;
        while(pq.size()){
            auto p=pq.top();pq.pop();
            int num=p.first,ind=p.second;
            if(!vis[ind]){
                vis[ind]=1;
                sum+=nums[ind];
                if(ind-1>=0 && !vis[ind-1]){vis[ind-1]=1;}
                if(ind+1<nums.size() && !vis[ind+1]){vis[ind+1]=1;}
            }
        }
        return sum;
    }
};