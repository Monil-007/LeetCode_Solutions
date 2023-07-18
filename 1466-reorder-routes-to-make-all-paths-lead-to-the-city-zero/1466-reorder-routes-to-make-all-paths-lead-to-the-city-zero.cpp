class Solution {
public:
    int count=0;
    void dfs(int u, int parent, unordered_map<int, vector<pair<int, int>>> &adj)
    {
        for(auto p : adj[u])
        {
            int v = p.first;
            int check = p.second;
            if(v != parent)
            {
                if(check == 1){count++;}
                dfs(v, u, adj);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto i : connections)
        {
            int u = i[0];
            int v = i[1];
            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
        }
        dfs(0, -1, adj);
        return count;
    }
};