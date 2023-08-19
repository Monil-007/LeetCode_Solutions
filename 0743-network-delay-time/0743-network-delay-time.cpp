class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int> dist(n+1,INT_MAX);
        for(auto i:times){
            adj[i[0]].push_back({i[1],i[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(pq.size()){
            int node=pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                int adjNode=it.first;
                int edgeW=it.second;
                if(dis+edgeW<dist[adjNode]){
                    dist[adjNode]=dis+edgeW;
                    pq.push({dis+edgeW,adjNode});
                }
            }
        }
        dist[0]=0;
        dist[k]=0;
        int rs=0;
        for(auto it:dist){
            rs=max(rs,it);
        }
        return rs==INT_MAX?-1:rs;
        // int rs=dist[1];
        // dist[k]=0;
        // for(auto it:dist){cout<<it<<" ";}
        // for(int i=1;i<dist.size();i++){
        //     if(dist[i]==INT_MAX){return -1;}
        //     rs=max(rs,dist[i]);
        // }
        // return rs;
    }
};