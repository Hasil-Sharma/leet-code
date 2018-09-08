// https://leetcode.com/problems/spiral-matrix/description/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0, dir = 0, i = 0, j = 0;
        vector<vector<int>> dirs = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
        vector<int> counter = {0, 0, 0, 0}, ans;
        if (m == 0 || n == 0) return ans;
        
        while(ans.size() != m * n){
            int ndir = (dir + 1) % 4;
            
            if (dirs[dir][0] == 1){
                for(; j < n - counter[ndir]; j++)
                    ans.push_back(matrix[i][j]);
                i += 1;
                j -= 1;
            } else if (dirs[dir][0] == -1){
                for(; j >= counter[ndir]; j--)
                    ans.push_back(matrix[i][j]);
                i -= 1;
                j += 1;
            } else if (dirs[dir][1] == -1){
                for(; i < m - counter[ndir]; i++)
                    ans.push_back(matrix[i][j]);
                j -= 1;
                i -= 1;
            } else if (dirs[dir][1] == 1){
                for(; i >= counter[ndir]; i--)
                    ans.push_back(matrix[i][j]);
                j += 1;
                i += 1;
            }
            
            counter[dir] += 1;
            dir = ndir;
        }
        
        return ans;
    }
};
