// https://leetcode.com/problems/n-queens/description/

class Solution {
public:
    
    void printBoard(vector<vector<int>>& board,int n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << board[i][j];
            }
            cout << endl;
        }
    }
    void solveNQueenHelper(int nthQueen, int n, vector<vector<int>>& board, vector<vector<string>>& answer){
        if (nthQueen == n){
            // n queens has been placed
            vector<string> tempans;
            for(int i = 0; i < n; i++){
                stringstream ss;
                for(int j = 0; j < n; j++){
                    ss << (board[i][j] == 0 ? "Q" : ".");
                }
                tempans.push_back(ss.str());
            }
            answer.push_back(tempans);
        } else {
            for(int i = 0; i < n; i++){
                // placing queen at board[row][i]
                if (board[nthQueen][i] == 0) {
                    // queen can be placed
                    changeBoard(board, nthQueen, i, n, 1);
                    // printBoard(board, n);
                    solveNQueenHelper(nthQueen + 1, n, board, answer);
                    changeBoard(board, nthQueen, i, n, -1);
                }
            }
        }
    }
    
    void changeBoard(vector<vector<int>>& board, int i, int j, int n, int delta){
        // vertical
        int r, c;
        for(r = 0; r < n; r++)
            board[r][j] += (r != i) ? delta : 0; // keeping the currently placed as zero
        
        // horizontal
        for(c = 0; c < n; c++)
            board[i][c] += (c != j) ? delta : 0;
        
        // upper left to down right slant
        r = i - 1; c = j - 1;
        while(r >= 0 && c >= 0)
            board[r--][c--] += delta;
        
        r = i + 1; c = j + 1;
        while (r < n && c < n)
            board[r++][c++] += delta;
        
        // upper right to down left slant
        r = i - 1; c = j + 1;
        while (r >= 0 && c < n)
            board[r--][c++] += delta;
        
        r = i + 1; c = j - 1;
        while (r < n && c >= 0)
            board[r++][c--] += delta;
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<string>> answer;
        solveNQueenHelper(0, n, board, answer);
        return answer;
    }
};
