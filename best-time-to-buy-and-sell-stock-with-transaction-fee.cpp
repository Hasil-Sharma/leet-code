// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int T_i_0 = 0, T_i_1 = -prices[0],temp;
        
        for(int i = 1; i < prices.size(); i ++){
            temp = T_i_0;
            // we've 0 stocks at the end
            // rest, sell
            T_i_0 = max(T_i_0, T_i_1 + prices[i] - fee);
            
            // We've 1 stocks at the end
            // rest, buy
            T_i_1 = max(T_i_1, temp - prices[i]);
        }
        
        return T_i_0;
    }
};
