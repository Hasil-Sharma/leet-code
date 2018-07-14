// https://leetcode.com/problems/surrounded-regions/description/

#define mp(A, B) make_pair(A, B)
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef stack<int> stki;
typedef queue<int> qi;
typedef deque<int> dqi;
typedef unordered_map<int, int> mpii;
vpii steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    void bfs(vector<vector<char>>& board, pii start){
        stack<pii> q;
        int m = board.size(), n = board[0].size();
        q.push(start);
        int i,j;
        
        while(!q.empty()){
            start = q.top();
            q.pop();
            i = start.first;
            j = start.second;
            board[i][j] = 'B';
            for(pii& step : steps){
                int ii = i + step.first, jj = j + step.second;
                if(ii >= 0 && jj >= 0 && ii < m && jj < n && board[ii][jj] == 'O')
                    q.push(mp(ii, jj));
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = m ? board[0].size() : 0;
        if (m == 0 || n == 0) return;
        
        for(int i = 0; i < n; i++){
            if (board[0][i] == 'O')
                bfs(board, mp(0, i));
            
            if (board[m-1][i] == 'O')
                bfs(board, mp(m-1, i));
        }
        
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                board[i][j] = board[i][j] == 'B' ? 'O' : 'X';
            }
        }
        
    }
};
