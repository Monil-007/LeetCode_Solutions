class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);
        vector<vector<int>> self(n,vector<int> (n,-1));
        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            indegree[v]++;
            adj[v].push_back(u);
            indegree[u]++;
            self[u][v]=1;
            self[v][u]=1;
        }
        int maxRank=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(self[i][j]==1){
                    maxRank=max(maxRank,indegree[i]+indegree[j]-1);
                }
                else{
                    maxRank=max(maxRank,indegree[i]+indegree[j]);
                }
            }
        }
        return maxRank;
    }
};