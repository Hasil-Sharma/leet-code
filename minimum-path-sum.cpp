// https://leetcode.com/problems/minimum-path-sum/description/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) { 
        int m = grid.size(), n = grid[0].size();
        // in case empty grid
        if (n == 0) return 0;
        
        int up[n], ans;
        
        up[0] = grid[0][0];
        // Updating sum for first row
        for(int i = 1; i < n; i++){
            up[i] = grid[0][i] + up[i-1];
        }
        
        // the case of single row
        ans = up[n-1];
        
        for(int i = 1; i < m; i++){
            // ans for first column for ith row
            ans = grid[i][0] + up[0];
            for(int j = 1; j < n; j++){
                ans = grid[i][j] + min(up[j], ans);
                up[j] = ans;
            }
            up[0] += grid[i][0];
        }
        
        return ans;
    }
};
