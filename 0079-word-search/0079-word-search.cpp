class Solution {
public:
    bool slv(int i,int j,int k,string &word,vector<vector<char>> &board,vector<vector<int>> &vis){
        if(k==word.size()){return true;}

        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()){return false;}
        if(vis[i][j]){return false;}
        if(board[i][j]!=word[k]){return false;}
        
        vis[i][j]=1;
        bool e=slv(i,j+1,k+1,word,board,vis);
        if(e){return true;}
        bool w=slv(i,j-1,k+1,word,board,vis);
        if(w){return true;}
        bool n=slv(i-1,j,k+1,word,board,vis);
        if(n){return true;}
        bool s=slv(i+1,j,k+1,word,board,vis);
        if(s){return true;}
        vis[i][j]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                bool fg=false;
                for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++){
                        cout<<vis[i][j]<<" ";
                    }
                    cout<<endl;
                }
                cout<<"-------------------------"<<endl;
                if(word[0]==board[i][j]){
                    fg=slv(i,j,0,word,board,vis);
                }
                if(fg){return true;}
            }
        }
        return false;
    }
};