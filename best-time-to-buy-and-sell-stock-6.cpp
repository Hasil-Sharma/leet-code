// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, min_price = prices.size() ? prices[0] : 0;
        
        for(auto price: prices){
            ans = max(ans, price - min_price);
            min_price = min(min_price, price);
        }
        return ans;
    }
};
