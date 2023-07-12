class Solution {
public:
    bool dfs(int node,vector<vector<int>> &graph,vector<int> &vis,vector<int> &pathVis,vector<int> &check){
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:graph[node]){
            if(vis[it]==-1){
                if(dfs(it,graph,vis,pathVis,check)){
                    check[it]=0;
                    return true;
                }
            }
            else{
                if(pathVis[it]==1){
                    check[it]=0;
                    return true;
                }
            }
        }
        pathVis[node]=0;
        check[node]=1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(),-1),pathVis(graph.size(),0);
        vector<int> check(graph.size(),0);
        vector<int> ans;
        for(int i=0;i<graph.size();i++){
            if(vis[i]==-1){
                bool fg=dfs(i,graph,vis,pathVis,check);
            }
        }
        for(int it=0;it<check.size();it++){
            if(check[it]){ans.push_back(it);}
        }
        return ans;
    }
};