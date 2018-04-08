// https://leetcode.com/problems/burst-balloons/description/

class Solution {
public:
    int maxCoins(vector<int>& inums) {
        // removing all the zeroes
        int nums[inums.size() + 2];
        int n = 1;
        for(int x : inums) if (x > 0) nums[n++] = x;
        nums[0] = nums[n++] = 1;
        
        int dp[n][n] = {};
        
        for(int k = 2; k < n; k++){
            for(int left = 0; left < n - k; left++){
                int right = left + k;
                for (int i = left + 1; i < right; i++)
                    dp[left][right] = max(dp[left][right],
                    nums[left] * nums[i] * nums[right] + dp[left][i] + dp[i][right]);
            }
        }
        
        return dp[0][n-1];
    }
};
