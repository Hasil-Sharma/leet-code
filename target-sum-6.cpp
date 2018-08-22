// https://leetcode.com/problems/target-sum/description/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        if (n == 0) return S == 0;
        vector<unordered_map<int, int>> dp(n + 1);
        
        dp[0][0] = 1;
        
        for(int i = 1; i <= n; i++){
            for(auto kv : dp[i - 1]){
                dp[i][kv.first + nums[i - 1]] += kv.second;
                dp[i][kv.first - nums[i - 1]] += kv.second;
            }
        }
        
        return dp[n][S];
    }
    
};
