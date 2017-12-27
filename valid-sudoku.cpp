// https://leetcode.com/problems/valid-sudoku/discuss/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // Check each row
        bool answer = true;
        for(int i = 0; i < 9 && answer; i++){
            // ith row
            vector<bool> hash_table(9, false);
            for(int j = 0; j < 9 && answer; j++){
                if(board[i][j] != '.'){
                    if (!hash_table[board[i][j] - '1']) hash_table[board[i][j] - '1'] = true;
                    else answer = false;
                }
            }
        }
        
        // Check each column
        for(int i = 0; i < 9 && answer; i++){
            // ith column
            vector<bool> hash_table(9, false);
            for(int j = 0; j < 9 && answer; j++){
                if(board[j][i] != '.'){
                    if(!hash_table[board[j][i] - '1']) hash_table[board[j][i] - '1'] = true;
                    else answer = false;
                }
            }
        }
        // Check each square
        for(int i = 1; i < 9 && answer; i += 3){
            for(int j = 1; j < 9 && answer; j += 3){
                vector<bool> hash_table(9, false);
                for(int a = i - 1; a <= i + 1 && answer; a++){
                    for(int b = j - 1; b <= j + 1 && answer; b++){
                        if(board[a][b] != '.'){
                            if(!hash_table[board[a][b] - '1']) hash_table[board[a][b] - '1'] = true;
                            else answer = false;
                        }
                    }
                }
            }
        }
        return answer;
    }
};

