// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX, ans = 0;
        
        for(int price : prices){
            if (price < mn) mn = price;
            else if (price > mn) ans = max(price - mn, ans);
        }
        
        return ans;
    }
};
