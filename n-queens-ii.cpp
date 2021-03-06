// https://leetcode.com/problems/n-queens-ii/description/
class Solution {
public:
        void solveNQueenHelper(int nthQueen, int n, vector<vector<int>>& board, int& answer){
        if (nthQueen == n){
            // n queens has been placed
            answer++;
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
    int totalNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        int answer = 0;
        solveNQueenHelper(0, n, board, answer);
        return answer;
    }
};
