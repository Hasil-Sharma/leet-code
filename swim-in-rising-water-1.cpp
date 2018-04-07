// https://leetcode.com/problems/swim-in-rising-water/description/

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size(), depth = 0, ans = -1;
        bool flag = true;
        while(ans < 0){
            if(grid[0][0] <= depth){
                vector<vector<bool>> visited(N, vector<bool>(N, false));
                stack<pair<int, int>> stk;
                stk.push({0, 0});  
                // DFS
                while(!stk.empty() && ans < 0){
                    pair<int, int> top = stk.top();
                    int i = top.first, j = top.second;
                    stk.pop();
                    visited[i][j] = true;
                    if (i == N - 1 && j == N - 1) 
                        ans = depth;
                    else {
                        if (i - 1 >= 0 && !visited[i - 1][j] && (grid[i - 1][j] <= depth)) {
                            stk.push({i - 1, j});
                        }
                        
                        if (i + 1 < N && !visited[i + 1][j] && (grid[i + 1][j] <= depth)) {
                            stk.push({i + 1, j});
                        }
                        
                        if (j - 1 >= 0 && !visited[i][j - 1] && (grid[i][j - 1] <= depth)) {
                            stk.push({i, j - 1});
                        }
                        
                        if (j + 1 < N && !visited[i][j + 1] && (grid[i][j + 1] <= depth)) {
                            stk.push({i, j + 1});
                        }
                    } 
                }
                
                // cout << endl;
            }
            
            depth++;
        }
        return ans;
    }
};
