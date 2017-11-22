// https://leetcode.com/problems/unique-paths-ii/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size(), ans, *up, left;
        
        if (n < 1) return 0;
        up = new int[n];
        memset(up, 0, n * sizeof(int));
        
        // Updating for the first row, even if there is one block no movement further
        for(int i = 0; i < n && obstacleGrid[0][i] == 0; i++){
            up[i] = 1;
        }
        
        bool flag = obstacleGrid[0][0] == 0 ? true : false;
        
        for(int i = 1; i < m ; i++){
            // Updating the first column, even if there is one block no movement further
            int left = (obstacleGrid[i][0] == 0 && flag) ? 1 : 0;
            flag = (left == 1) ? true : false;
            
            for(int j = 1; j < n; j++){
                // Check if it is possible to reach the grid
                ans = (obstacleGrid[i][j] == 0) ? left + up[j] : 0;
                left = ans;
                up[j] = ans;
            }
        }
            
        return obstacleGrid[m-1][n-1] == 0 ? up[n - 1] : 0;
    }
};

