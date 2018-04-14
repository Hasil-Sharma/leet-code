// https://leetcode.com/problems/island-perimeter/description/
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int hash[5] = {0};
        int steps[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int m = grid.size(), n = grid.size() ? grid[0].size() : 0;
        int ans = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (grid[i][j]){
                    int count = 0;
                    for(int p = 0; p < 4; p++){
                        int r = i + steps[p][0], c = j + steps[p][1];
                        if(r > -1 && c > -1 && r < m && c < n && grid[r][c])
                            count++;
                    }
                    hash[count]++;
                }
            }
        }
        
        for(int i = 0; i < 5; i++){
            ans += hash[i]*(4 - i);
        }
        
        return ans;
    }
};
