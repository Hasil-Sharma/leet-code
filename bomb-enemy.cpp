// https://www.lintcode.com/problem/bomb-enemy/description

class Solution {
public:
    /**
     * @param grid: Given a 2D grid, each cell is either 'W', 'E' or '0'
     * @return: an integer, the maximum enemies you can kill using one bomb
     */
    int maxKilledEnemies(vector<vector<char>> &grid) {
        // write your code here
        int m = grid.size(), n = m ? grid[0].size() : 0, ans = 0, row = 0;
        if (m == 0 || n == 0)
            return 0;
        // m rows and n columns
        vector<int> column(n, -1);
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (i == 0 || grid[i - 1][j] == 'W'){
                    column[j] = getColSum(grid, i, j);
                    cout << j << endl;
                }
                
                if (j == 0 || grid[i][j - 1] == 'W'){
                    row = getRowSum(grid, i, j);
                }
                
                if (grid[i][j] == '0'){
                    ans = max(ans, row + column[j]);
                }
            }
        }
        
        return ans;
    }
    
    int getRowSum(vector<vector<char>> &grid, int i, int j){
        int ans = 0;
        while(j < grid[0].size() && grid[i][j] != 'W'){
            ans += (grid[i][j++] == 'E' ? 1 : 0);
        }
        
        return ans;
    }
    
    int getColSum(vector<vector<char>> &grid, int i, int j){
        int ans = 0;
        while(i < grid.size() && grid[i][j] != 'W'){
            ans += (grid[i++][j] == 'E' ? 1 : 0);
        }
        
        return ans;
    }
};
