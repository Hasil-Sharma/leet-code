// https://leetcode.com/problems/max-area-of-island/description/

class Solution {
public:
    
    vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, ans = 0;
        
        if (m == 0 || n == 0)
            return ans;
        vector<vector<bool>> mask(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (mask[i][j] || grid[i][j] == 0)
                    continue;
                ans = max(ans, search(grid, i, j, mask));
            }
        }
        
        return ans;
    }
    
    int search(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& mask){
        int m = grid.size(), n = m ? grid[0].size() : 0, ans = 0;
        stack<pair<int, int>> stk;
        stk.push({i, j});
        while(!stk.empty()){
            auto top = stk.top();
            stk.pop();
            if (!(top.first >= 0 && top.first < m && top.second >= 0 && top.second < n && grid[top.first][top.second] == 1
                 && !mask[top.first][top.second]))
                continue;
            ans++;
            mask[top.first][top.second] = true;
            for (auto move : moves)
                stk.push({top.first + move.first, top.second + move.second});
        }
        return ans;
    }
};
