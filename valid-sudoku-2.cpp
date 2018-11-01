// https://leetcode.com/problems/valid-sudoku/description/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> rows = vector<int>(9, 0), cols = vector<int>(9, 0), box = vector<int>(9, 0);
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int val = board[i][j] - '0' - 1, k = i/3*3 + j/3, idx = (1 << val);
                    if(rows[i] & idx || cols[j] & idx || box[k] & idx)
                        return false;
                    rows[i] |= idx;
                    cols[j] |= idx;
                    box[k] |= idx;
                }
            }
        }
        
        return true;
    }
};
