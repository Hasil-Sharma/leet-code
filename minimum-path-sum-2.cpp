// https://leetcode.com/problems/minimum-path-sum/description/

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
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        if (m == 0 || n == 0)
            return 0;
        vi dp(n);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (i == 0 && j == 0) dp[j] = grid[i][j];
                else if (i == 0) dp[j] = grid[i][j] + dp[j-1];
                else if (j == 0) dp[j] = grid[i][j] + dp[j];
                else dp[j] = grid[i][j] + min(dp[j], dp[j-1]);
            }
        }
        
        return dp[n - 1];
    }
};
