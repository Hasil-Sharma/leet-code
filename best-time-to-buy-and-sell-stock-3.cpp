// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, currMin = prices.size() ? prices[0] : 0;
        for(int p : prices){
            ans = max(ans, p - currMin);
            currMin = min(p, currMin);
        }
        return ans;
    }
};
