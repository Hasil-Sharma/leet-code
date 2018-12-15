// https://leetcode.com/problems/coin-change/description/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> dp;
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            dp[i] = INT_MAX;
            for(auto coin : coins){
                if (i - coin >= 0 && dp[i-coin] != INT_MAX)
                    dp[i] = min(dp[i-coin] + 1, dp[i]);
            }
        }
        
        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};
