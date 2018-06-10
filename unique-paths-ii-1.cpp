// https://leetcode.com/problems/unique-paths-ii/description/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = m ? obstacleGrid[0].size() : 0;
        if (m == 0 || n == 0)
            return 0;
        
        vector<int> dp(n, 0);
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (i == 0){
                    dp[j] = obstacleGrid[i][j] ? 0 : (j ? dp[j - 1] : 1);
                } else {
                    dp[j] =  obstacleGrid[i][j] ? 0 : dp[j] + dp[j - 1];
                }
            }
        }
        
        return dp[n - 1];
    }
};
