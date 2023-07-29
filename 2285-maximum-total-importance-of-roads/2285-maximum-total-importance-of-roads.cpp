class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n,0);
        for(auto i:roads){
            int u=i[0];
            int v=i[1];
            indegree[u]++;
            indegree[v]++;
        }
        map<int,int> mp;
        priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>> pq;
    
        for(int i=0;i<n;i++){
            pq.push({indegree[i],i});
        }
        int tmr=1;
        while(pq.size()){
            auto p=pq.top();pq.pop();
            mp[p.second]=tmr++;
        }
        long long sum=0;
        for(auto it:roads){
            sum+=mp[it[0]]+mp[it[1]];
        }
        return sum;
    }
};