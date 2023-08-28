class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        int delr[] = {0, -1, -1, -1, 0, 1, 1, 1};
        int delc[] = {1, 1, 0, -1, -1, -1, 0, 1};
        
        vector<vector<int>> newBoard = board;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                int liveNeighbors = 0;

                for (int i = 0; i < 8; i++) {
                    int nr = r + delr[i];
                    int nc = c + delc[i];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && (board[nr][nc] == 1 ||  board[nr][nc] == -1)) {
                        liveNeighbors++;
                    }
                }

                if (board[r][c] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                    newBoard[r][c] = -1;
                } 
                else if (board[r][c] == 0 && liveNeighbors == 3) {
                    newBoard[r][c] = 2;
                }
            }
        }

        // Update the board state
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                
                if (newBoard[r][c] == -1) {
                    board[r][c] = 0;
                } 
                else if (newBoard[r][c] == 2) {
                    board[r][c] = 1;
                }
            }
        }
    }
};