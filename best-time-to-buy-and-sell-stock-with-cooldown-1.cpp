// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

typedef vector<vector<int>> vvi;
typedef vector<int> vi;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), cooldown = 1;
        if (n == 0) return 0;
        vvi dp(n + 1, vi(2,0));
        
        dp[0][1] = INT_MIN; // you cannot buy a non-existent item
        dp[1][1] = -prices[0];
        
        for(int i = 2; i <= n; i++){
            dp[i][0] = max(dp[i - 1][0], dp[i-1][1] + prices[i-1]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1 - cooldown][0] - prices[i-1]);
        }
        
        return dp[n][0];
    }
};
