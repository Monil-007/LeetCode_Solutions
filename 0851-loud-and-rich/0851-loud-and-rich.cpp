class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n);
        for (auto & edge: richer)
        {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0){q.push(i);}
        }
        vector<int> answer(n);
        for (int i=0;i<n;i++) {answer[i]=i;}
        while (q.size())
        {
            int current=q.front();
            q.pop();
            for (int adj : graph[current])
            {
                if (quiet[answer[current]] < quiet[answer[adj]]){
                    answer[adj] = answer[current];
                }
                indegree[adj]--;
                if (indegree[adj] == 0){
                    q.push(adj);
                }
            }
        }
        return answer;
    }
};