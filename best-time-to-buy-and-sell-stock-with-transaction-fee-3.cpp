// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int sell = 0, buy = -prices[0], psell;
        for(int i = 2; i <= n; i++){
            psell = sell;
            sell = max(sell, buy + prices[i-1] - fee);
            buy = max(buy, psell - prices[i-1]);
        }
        return sell;
    }
};
