// https://leetcode.com/problems/minesweeper/description/

class Solution {
public:
    typedef vector<vector<char>> vvc;
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size();
        vector<vector<char>> answer(m, vector<char>(n, '\0'));
        dfs(board, answer, click, m, n);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                answer[i][j] = answer[i][j] == '\0' ? board[i][j] : answer[i][j];
        return answer;
    }
    
    void dfs(vvc board, vvc& answer, vector<int> click, int m , int n){
        vector<vector<int>> steps = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
        stack<vector<int>> stk;
        stk.push(click);
        while(!stk.empty()){
            click = stk.top();
            stk.pop();
            
            char c = board[click[0]][click[1]];
            
            if (c == 'M') {
                answer[click[0]][click[1]] = 'X';
                return;
            } else if (c == 'E') {
                
                int revAdjMines = 0;
                for(auto step : steps){
                    int _m = click[0] + step[0], _n = click[1] + step[1];
                    if (_m >= 0 && _m < m && _n >= 0 && _n < n){
                        revAdjMines += (board[_m][_n] == 'X' || board[_m][_n] == 'M') ? 1 : 0;
                    }
                }
                if (revAdjMines > 0){
                    answer[click[0]][click[1]] = '0' + revAdjMines;
                } else {
                    answer[click[0]][click[1]] = 'B';
                    for(auto step : steps){
                        int _m = click[0] + step[0], _n = click[1] + step[1];
                        if (_m >= 0 && _m < m && _n >= 0 && _n < n && answer[_m][_n] == '\0'){
                            stk.push({_m, _n});
                        }
                    }
                }
            }
        }
        return;
    } 
};
