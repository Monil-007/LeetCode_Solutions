class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        vector<long long> ksmall;
        long long sum=0;
        vector<pair<int,int>> v;
        for(int i=0;i<nums2.size();i++){
            v.push_back({nums2[i],nums1[i]});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        for(auto it:v){
            sum+=it.second;
            if(pq.size()==k){
                sum-=pq.top();
                pq.pop();
            }
            pq.push(it.second);
            ksmall.push_back(sum);
        }
        for(auto i:v){cout<<i.first<<"-"<<i.second<<" ";}
        cout<<endl;
        for(auto j:ksmall){cout<<j<<" ";}
        long long res=0;
        for(int i=k-1;i<v.size();i++){
            res=max(res,ksmall[i]*v[i].first);
        }
        return res;
    }
};