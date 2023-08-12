class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<int> vis(m,0);
        for(int tri=0;tri<m;tri++){
            if(vis[tri]==1){continue;}
            vis[tri]=1;
            for(int trv=0;trv<n;trv++){
            int i=tri,j=trv;
            int tg=matrix[i][j];
            while(i<m && j<n){
                int cn=matrix[i++][j++];
                
                if(cn!=tg){return false;}
            }
        }
        }
        
        return true;
    }
};