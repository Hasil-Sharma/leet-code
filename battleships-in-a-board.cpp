// https://leetcode.com/problems/battleships-in-a-board/description/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        for(int row_i = 0; row_i < board.size(); ++row_i)
            for(int col_i = 0; col_i < board[0].size(); ++col_i){
                if(row_i == 0){
                    // row first
                    if(col_i == 0 && board[row_i][col_i] == 'X') count++;
                    else if(board[row_i][col_i] == 'X' && board[row_i][col_i - 1] == '.') count++;
                } else {
                    if(col_i == 0 && board[row_i][col_i] == 'X' && board[row_i - 1][col_i] == '.') count++;
                    else if(board[row_i][col_i] == 'X' && board[row_i][col_i - 1] == '.' && board[row_i - 1][col_i] == '.') count++;
                }
            }
        
        return count;
    }
};
