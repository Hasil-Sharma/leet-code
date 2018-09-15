// https://leetcode.com/problems/game-of-life/description/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = m ? board[0].size() : 0;
        vector<pair<int,int>> steps = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int live = 0;
                for(auto step : steps){
                    int ii = i + step.first, jj = j + step.second;
                    if (ii >= 0 && jj >= 0 && ii < m && jj < n)
                        live += (board[ii][jj] & 1);
                }
                
                if (((board[i][j] & 1) && live < 4 && live >= 2) || (!(board[i][j] & 1) && live == 3))
                    board[i][j] = (board[i][j] | 2);
            }
        }
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                board[i][j] >>= 1;
    }
};
