// https://leetcode.com/problems/valid-sudoku/description/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = 9, mask = 0, count ;
        // checking column by column
        for(int i = 0; i < m; i++){
            mask = 0;
            for(int j = 0; j < m; j++){
                if (board[j][i] == '.')
                    continue;
                if (mask & (1 << board[j][i] - '0'))
                    return false;
                mask = (mask | (1 << (board[j][i] - '0')));
            }
        }
        
        // checking row by row
        for(int i = 0; i < m; i++){
            mask = 0;
            count = 0;
            for(int j = 0; j < m; j++){
                if (board[i][j] == '.')
                    continue;
                if (mask & (1 << board[i][j] - '0'))
                    return false;
                mask = (mask | (1 << (board[i][j] - '0')));
            }
        }
        
        // checking 3 X 3
        vector<vector<int>> dir = {{0, 0}, {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        for(int i = 1; i < m; i+=3){
            for(int j = 1; j < m; j+=3){
                mask = 0;
                for(auto dd : dir){
                    if (board[i + dd[0]][j + dd[1]] == '.')
                        continue;
                    if (mask & (1 << board[i + dd[0]][j + dd[1]] - '0'))
                        return false;
                    mask = (mask | (1 << (board[i + dd[0]][j + dd[1]] - '0')));
                }
            }
        }
        
        return true;
    }
};
