// https://www.lintcode.com/problem/decode-ways/description

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
    /**
     * @param s: a string,  encoded message
     * @return: an integer, the number of ways decoding
     */
     
    bool check(string &s, int idx){
        int val = (s[idx - 1] - '0') * 10 + (s[idx] - '0');
        return val >= 10 && val <= 26;
    }
    int numDecodings(string &s) {
        // write your code here
        int n = s.length(), i;
        if ( n == 0) return 0;
        vi dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = s[0] != '0' ? 1 : 0;
        ff(i, 2, n + 1){
            dp[i] = (s[i-1] != '0' ? dp[i-1] : 0) + (check(s, i-1) ? dp[i-2] : 0);
        }
        return dp[n];
    }
};
