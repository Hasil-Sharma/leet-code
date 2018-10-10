// https://leetcode.com/problems/word-search-ii/description/

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
vpii steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_map<string, bool> ans;
        int m = board.size(), n = m ? board[0].size() : 0;
        if (!m || words.size() == 0) return {};
        
        
        for(auto word : words){
            int i, j;
            ff(i, 0, m){
                ff(j, 0, n){
                    if (word[0] == board[i][j] && find(board, word, 1, i, j, m, n))
                        ans[word] = true;
                }
            }
        }
        vs output;
        for(auto kv : ans)
            output.push_back(kv.first);
        
        return output;
    }
    
    bool find(vvc& board, string& word, int idx, int i, int j, int m, int n){
        if (board[i][j] == '#') return false;
        else if (idx == word.length()) return true;
        
        char temp = board[i][j];
        board[i][j] = '#';
        bool flag = false;
        
        for(auto step : steps){
            int ii = i + step.first, jj = j + step.second;
            if (ii >= 0 && ii < m && jj >= 0 && jj < n && word[idx] == board[ii][jj])
                flag = flag || find(board, word, idx + 1, ii, jj, m, n);
        }
        
        board[i][j] = temp;
        
        return flag;
    }
};
