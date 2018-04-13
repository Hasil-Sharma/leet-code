//https://leetcode.com/problems/number-of-islands/submissions/1

class Solution {
public:
    vector<pair<int, int>> steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    void dfs(vector<vector<char>>& grid, int i, int j){
        int m = grid.size(), n = grid[0].size();

        stack<pair<int, int>> stk;
        stk.push({i, j});
        grid[i][j] = '0';
        
        while(!stk.empty()){
            auto top = stk.top();
            stk.pop();
            
            for(auto step : steps){
                int r = top.first + step.first;
                int c = top.second + step.second;
                if(r > -1 && r < m && c > -1 && c < n && (grid[r][c] == '1')){
                    stk.push({r, c});
                    grid[r][c] = '0';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid.size() ? grid[0].size() : 0, ans = 0;
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(grid, i, j);
                }   
        
        return ans;
    }
};
