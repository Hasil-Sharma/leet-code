// https://leetcode.com/problems/longest-palindromic-substring/description/

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
    string longestPalindrome(string s) {
        int n = s.length();
        vvb dp(n, vb(n, false));
        int start = 0, maxLen = 1, i, k, j;
        
        ff(i, 0, n)
            dp[i][i] = true;
        
        ff(i, 0, n-1)
            if (s[i] == s[i+1]){
                dp[i][i+1] = true;
                start = i;
                maxLen = 2;
            }
        ff(k, 3, n+1){
            ff(i, 0, n-k+1){
                j = i + k - 1;
                if (dp[i+1][j-1] && s[i] == s[j]){
                    dp[i][j] = true;
                    start = i;
                    maxLen = k;
                }
            }
        }
        
        return s.substr(start, maxLen);
    }
};
