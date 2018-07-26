// https://www.lintcode.com/problem/word-search/description

#define mp(A, B) make_pair(A, B)
#define ff(i, m, n) for(i = m; i < n; i++)
#define ffr(i, m, n) for(i = m; i >= n; i--)
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<pair<int, int>> vpii;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef stack<int> stki;
typedef queue<int> qi;
typedef deque<int> dqi;
typedef queue<pair<int, int>> qpii;
typedef unordered_map<int, int> umpii;
typedef set<int> si;
typedef unordered_set<int> usi;
vpii steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
 bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = m ? board[0].size() : 0;
        if (m == 0 || n == 0 || word.length() == 0) return word.length() == 0;
        vvb mask(m, vb(n));
        int i, j;
        ff(i, 0, m){
            ff(j, 0, n){
                if (board[i][j] == word[0]){
                    mask[i][j] = true;
                    if (dfs(board, word, mask, 1, i, j)) return true;
                    mask[i][j] = false;
                }
            }
        }
        return false;
    }
    
    bool dfs(vvc& board, string& word, vvb& mask, int h, int i, int j){
        if (word.size() == h) return true;
        int m = board.size(), n = board[0].size();
        for(auto step: steps){
            int ii = i + step.first, jj = j + step.second;
            if (ii >= 0 && jj >= 0 && ii < m && jj < n && !mask[ii][jj] && word[h] == board[ii][jj]){
                mask[ii][jj] = true;
                if (dfs(board, word, mask, h + 1, ii, jj)) return true;
                mask[ii][jj] = false;
            }
        }
        return false;
    }
};
