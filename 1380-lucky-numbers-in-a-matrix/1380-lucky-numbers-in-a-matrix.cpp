class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<int> ans;
        unordered_map<int,int> rowmp;
        for(int i=0;i<m;i++){
            int mn=INT_MAX;
            for(int j=0;j<n;j++){
                if(matrix[i][j]<mn){
                    mn=matrix[i][j];
                }
            }
            rowmp[mn]=1;
        }
        for(int j=0;j<n;j++){
            int mx=INT_MIN;
            for(int i=0;i<m;i++){
                if(matrix[i][j]>mx){
                    mx=matrix[i][j];
                }
            }
            if(rowmp[mx]){ans.push_back(mx);}
        }
        return ans;
    }
};