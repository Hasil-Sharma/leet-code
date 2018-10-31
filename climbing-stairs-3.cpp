// https://leetcode.com/problems/climbing-stairs/description/

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
    int climbStairs(int n) {
        if (n < 2) return n;
        vvi res = {{1, 1}, {1, 0}}, ans = {{1, 0}, {0, 1}};
        exponentiation(res, ans, n);
        return ans[0][0];
    }
    
    void exponentiation(vvi& res, vvi& ans, int n){
        while(n > 0){
            if (n & 1)
                multiply(ans, res);
            n = n >> 1;
            multiply(res, res);
        }
    }
    
    void multiply(vvi& x, vvi& y){
        int a = x[0][0]*y[0][0] + x[0][1]*y[1][0];
        int b = x[0][0]*y[0][1] + x[0][1]*y[1][1];
        int c = x[1][0]*y[0][0] + x[1][1]*y[1][0];
        int d = x[1][0]*y[0][1] + x[1][1]*y[1][1];
        
        x[0][0] = a;
        x[0][1] = b;
        x[1][0] = c;
        x[1][1] = d;
    }
};
