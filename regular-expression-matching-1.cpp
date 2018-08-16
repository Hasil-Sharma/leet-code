// https://leetcode.com/problems/regular-expression-matching/description/

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

template <typename T>
void printVec(T const& t){
    for(auto e :  t)
        cout << e << ",";
    cout << endl;
}
class Solution {
public:
    vvi dp;
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        dp = vvi(m + 1, vi(n + 1, -1));
        dp[0][0] = helper(s, p, 0, 0, m, n);
        return dp[0][0];
    }
    
    int helper(string &s, string &p, int i, int j, int m, int n){
        if (j == n) return i == m;
        else if (dp[i][j] != -1) return dp[i][j] == 1;
        // j + 1 < n
        // check if the first character of current slice matches
        bool firstMatch = (i < m) && (s[i] == p[j] || p[j] == '.');
        if ( j  + 1 < n && p[j + 1] == '*'){
            // check with remove the matched corrector or with removing the pattern itself
            dp[i][j] = (firstMatch && helper(s, p, i + 1, j, m, n)) || helper(s, p, i, j + 2, m, n);
        } else {
            // removing the match characters and recurring normally
            dp[i][j] = firstMatch && helper(s, p, i + 1, j + 1, m, n);
        }
        return dp[i][j];
    }
};
