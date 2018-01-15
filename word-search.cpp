// https://leetcode.com/problems/word-search/description/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        int m = board.size(), n = board[0].size();
        
        // m rows and n columns 
        
        for(int i = 0; i < m && !ans; i++){
            for(int j = 0; j < n && !ans; j++){
                if (board[i][j] == word[0]) {
                    ans = util(board, word, 1, i, j);
                }
            }
        }
        
        return ans;
    }
    
    bool util(vector<vector<char>>& board,string& word, int index, int m, int n){
        bool ans;
        char t = board[m][n];
        board[m][n] = '\0';
        ans = helper(board, word, index, m, n);
        board[m][n] = t;
        return ans;
    }
    
    bool helper(vector<vector<char>>& board, string& word, int index, int m, int n){
        if (index == word.length()) return true;
        
        bool ans = false;
        
        // move to left
        if (!ans && n - 1 >= 0 && board[m][n - 1] == word[index]){
            ans = util(board, word, index + 1, m , n - 1);
        }
        // move to right
        if (!ans && n + 1 < board[0].size() && board[m][n + 1] == word[index]){
            ans = util(board, word, index + 1, m , n + 1);
        }
        
        // move up
        if (!ans && m - 1 >= 0 && board[m - 1][n] == word[index]){
            ans = util(board, word, index + 1, m - 1, n);
        }
        
        // move down
        if (!ans && m + 1 < board.size() && board[m + 1][n] == word[index]){
            ans = util(board, word, index + 1, m + 1, n);
        }
        
        return ans;
    }
};
