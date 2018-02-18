// https://leetcode.com/problems/game-of-life/description/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = n > 0 ? board[0].size() : 0, count;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                count = 0;
                // Each cell [upper bit, lower bit] = [future state, previous state]
                for(int k = max(0, i - 1); k <= min(n - 1, i + 1); k++){
                    for(int l = max(0, j - 1); l <= min(m - 1, j + 1); l++){
                        count += board[k][l] & 1;
                    }
                }

                count -= board[i][j];

                // live cell
                if (board[i][j] == 1) {
                    // fewer than two neighbors dies or more than three live neighbors dies
                    if (count < 2 || count > 3) board[i][j] = 1;
                    // two or three live neighbors lives
                    else if (count >= 2 && count <= 3) board[i][j] |= 2;
                } else if (count == 3) board[i][j] |= 2; //  dead cell with exactly three live neighbors becomes a live cel
                
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                board[i][j] = board[i][j] >> 1;
            }
        }
    }
};
