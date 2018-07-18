// https://leetcode.com/problems/unique-paths/description/
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
typedef queue<pair<int, int>> qpii;
typedef unordered_map<int, int> umpii;
typedef set<int> si;
vpii steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    int uniquePaths(int m, int n) {
        umpii dp;
        int key, M = max(m,n) + 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                key = M*i + j;
                if(i == 0 || j == 0){
                    dp[key] = 1;
                } else {
                    dp[key] = dp[key - M] + dp[key - 1];
                }
            }
        }
        return dp[key];
    }
};
