// https://leetcode.com/problems/paint-house-ii/description/

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), k = n ? costs[0].size() : 0, ans = INT_MAX;
        if (n == 0) return 0;
        
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
        
        for(int i = 1; i <= k; i++){
            dp[0][i] = 0;
            dp[1][i] = costs[0][i-1];
        }
        
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= k; j++){
                for(int a = 1; a <= k; a++){
                    if (a == j) continue;
                    dp[i][j] = min(dp[i-1][a] + costs[i-1][j-1], dp[i][j]);
                }
            }
        }
        
        for(int i = 1; i <= k; i++)
            ans = min(ans, dp[n][i]);
        return ans;
    }
};
