class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // soldiers, index
        vector<int> result;
        vector<pair<int,int>> rows(mat.size()); 

        for (int i = 0; i < mat.size(); i++) {
            rows[i] = make_pair(accumulate(mat[i].begin(), mat[i].end(), 0), i);
        }

        // O(n), min heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq(rows.begin(), rows.end());

        while (!pq.empty() && k > 0) {
            result.emplace_back(pq.top().second);
            pq.pop();
            k--;
        }

        return result;
    }
};