class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& pat) {
        int n=pat.size();
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<int> dist(n,INT_MAX);
        dist[0]=0;
        while(pq.size()){
            int node=pq.top().second,dis=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                int adjNode=it;
                if(1+dis<dist[adjNode]){
                    dist[adjNode]=1+dis;
                    pq.push({1+dis,adjNode});
                }
            }
        }
        int rs=0;
        for(auto it:dist){cout<<it<<" ";}
        for(int i=1;i<dist.size();i++){
            if(dist[i]==INT_MAX){return -1;}
            int lastPackDiv=(2*dist[i])/pat[i];
            int lastPackTime=pat[i]*lastPackDiv;
            if(lastPackTime==2*dist[i]){
                lastPackTime-=pat[i];
            }
            rs=max(rs,lastPackTime+2*dist[i]);
        }
        return rs+1;
    }
};