// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, n = prices.size(), buy = n ? prices[0]: 0;
        
        for(int price : prices){
            ans = max(ans, price - buy);
            buy = min(buy, price);
        }
        
        return ans;
    }
};
