// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), ans = 0;
        if (n <= 0) return ans;
        
        vector<int> sell(n + 1, 0), buy(n + 1, 0);
        
        buy[0] = -prices[0];
        sell[0] = 0;
        
        for(int i = 1; i <= n; i++){
            sell[i] = i == n ? sell[i-1] : max(sell[i-1], buy[i-1] + prices[i]);
            buy[i] = i == n ? buy[i-1] : max(buy[i-1], sell[i-1] - prices[i]);
        }
        
        return sell[n];
    }
};
