// https://leetcode.com/problems/game-of-life/description/

#define mp(A, B) make_pair(A, B)
#define ff(i, m, n) for(i = m; i < n; i++)
#define ffr(i, m, n) for(i = m; i >= n; i--)
#define ss(v) sort(v.begin(), v.end())
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<pair<int, int>> vpii;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vector<string>> vvs;
typedef stack<int> stki;
typedef queue<int> qi;
typedef deque<int> dqi;
typedef queue<pair<int, int>> qpii;
typedef unordered_map<int, int> umpii;
typedef unordered_map<int, vi> umpiv;
typedef set<int> si;
typedef unordered_set<int> usi;
vpii steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};

class Solution {
public:
    int getCount(vvi& board, int i, int j, int n, int m){
        int count = 0;
        for(auto step: steps){
            int ii = i + get<0>(step), jj = j + get<1>(step);
            if (ii >= 0 && jj >= 0 && ii < n && jj < m)
                count += (board[ii][jj] & 1);
        }
        return count;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = n ? board[0].size() : 0;
        int i, j;
        
        ff(i, 0, n)
            ff(j, 0, m){
            int count = getCount(board, i, j, n, m);
            if (board[i][j]&1){
                if (count < 2) board[i][j] |= 1;
                else if (count < 4) board[i][j] |= 2;
                else board[i][j] |= 1;
            } else if (count == 3) board[i][j] |= 2;
        }
        
        ff(i, 0, n)
            ff(j, 0, m)
            board[i][j] >>= 1;
    }
};
