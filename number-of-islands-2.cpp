// https://leetcode.com/problems/number-of-islands/description/

class Solution {
public:
    
    vector<pair<int, int>> steps = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0, m = grid.size(), n = m ? grid[0].size() : m;
        if (m == 0 || n == 0) return 0;
        
        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n; j++){
                if (grid[i][j] == '1'){
                    ans += 1;
                    dfs(grid, make_pair(i, j));
                }
            }
        }
        
        return ans;
    }
    
    
    void dfs(vector<vector<char>>& grid, pair<int, int> p){
        stack<pair<int, int>> stk;
        stk.push(p);
        int m = grid.size(), n = m ? grid[0].size() : m;
        while(!stk.empty()){
            p = stk.top();
            stk.pop();
            int _m = p.first, _n = p.second;
            if (grid[_m][_n] == '1'){
                grid[_m][_n] = '0';
                
                for(auto step : steps){
                    _m = p.first + step.first; 
                    _n = p.second + step.second;
                    
                    if (_m >= 0 && _m < m && _n >= 0 && _n < n)
                        stk.push(make_pair(_m, _n));
                }
            }
        }
    }
};
