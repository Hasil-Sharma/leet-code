// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

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
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vvi dp(n + 1, vi(2, 0));
        
        dp[0][0] = 0;
        dp[0][1] = INT_MIN;
        for(int i = 1; i <= n; i++){
            dp[i][0] = i == 1 ? 0 : max(dp[i-1][1] + prices[i-1] - fee, dp[i-1][0]);
            dp[i][1] = max(dp[i-1][0] - prices[i-1], dp[i-1][1]);
        }
        
        return dp[n][0];
    }
};
