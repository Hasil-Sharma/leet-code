// https://leetcode.com/problems/game-of-life/description/

class Solution {
public:
    
    // Any live cell with fewer than two live neighbors dies, as if caused by under-population.
    // Any live cell with two or three live neighbors lives on to the next generation.
    // Any live cell with more than three live neighbors dies, as if by over-population..
    // Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = m ? board[0].size() : 0;
        vector<vector<int>> steps = {{-1, 1}, {0, 1}, {1, 1}, {1, 0},
                                     {1, -1}, {0, -1}, {-1, -1}, {-1, 0}};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int count = 0;
                for(auto step: steps){
                    int ii = i + step[0], jj = j + step[1];
                    if (ii >= 0 && jj >= 0 && ii < m && jj < n)
                        count += (board[ii][jj]&1);
                }
                
                board[i][j] |= board[i][j] ? ((count == 2 || count == 3)<<1) : ((count == 3) << 1);
            }
        }
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                board[i][j] = (board[i][j] >> 1);
    }
};
