// https://leetcode.com/problems/word-search/description/

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
typedef vector<char> vc;
typedef vector<vector<string>> vvs;
typedef stack<int> stki;
typedef queue<int> qi;
typedef deque<int> dqi;
typedef queue<pair<int, int>> qpii;
typedef unordered_map<int, int> umpii;
typedef set<int> si;
typedef unordered_set<int> usi;
vpii steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

template <typename T>
void printVec(T const& t){
    for(auto e :  t)
        cout << e << ",";
    cout << endl;
}
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = m ? board[0].size() : 0;
        if (!m) return word.length() == 0;
        vvb mask(m, vb(n, false));
        int i,j;
        ff(i, 0, m){
            ff(j, 0, n){
                if (dfs(board, word, mask, 0, i, j))
                    return true;
            }
        }
        return false;
    }
    
    bool dfs(vvc& board, string& word, vvb& mask, int idx, int i, int j){
        int m = board.size(), n = board[0].size();
        if (word[idx] == board[i][j] && idx == word.length() - 1) return true;
        else if (word[idx] != board[i][j]) return false;
        bool flag = false;
        mask[i][j] = true;
        for(auto step : steps){
            int ii = i + step.first, jj = j + step.second;
            if (ii >= 0 && jj >= 0 && ii < m && jj < n && !mask[ii][jj])
                flag = dfs(board, word, mask, idx + 1, ii, jj);
            if (flag) break;
        }
        mask[i][j] = false;
        return flag;
    }
};
