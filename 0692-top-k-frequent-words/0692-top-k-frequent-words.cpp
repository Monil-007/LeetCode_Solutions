class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for(auto it:words){
            freq[it]++;
        }
        priority_queue<pair<int,string>> pq;
        for(auto it:freq){
            pq.push({it.second,it.first});
        }
        vector<string> ans;
        int k1=k,k2=0;
        while(pq.size() && k2<k){
            int curr=pq.top().first;
            vector<string> temp;
            while(pq.size() && pq.top().first==curr && k2<k){
                temp.push_back(pq.top().second);
                pq.pop();
                k2--;
            }
            sort(temp.begin(),temp.end());
            for(auto it:temp){ans.push_back(it);}
        }
        vector<string> ret;
        for(int i=0;i<k1;i++){
            ret.push_back(ans[i]);
        }
        return ret;
    }
};