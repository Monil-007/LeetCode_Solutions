class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        priority_queue<pair<double,int>> pq;
        vector<double> dist(n,DBL_MIN);
        vector<vector<pair<int,double>>> adj(n);
        vector<int> vis(n,0);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double dist=succProb[i];
            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});
        }
        double initdist=1;
        pq.push({initdist,start});
        dist[start]=(double)1;
        while(pq.size()){
            double dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            //vis[node]=1;
            for(auto it:adj[node]){
                int adjNode=it.first;
                double edgeW=it.second;
                if(dis*edgeW>dist[adjNode] ){
                    dist[adjNode]=dis*edgeW;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return dist[end];
        
    }
};