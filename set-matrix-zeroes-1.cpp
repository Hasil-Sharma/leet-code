// https://leetcode.com/problems/set-matrix-zeroes/description/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col1 = 1, n = matrix.size(), m = n ? matrix[0].size() : 0;
        
        for(int i = 0; i < n; i++){
            if (matrix[i][0] == 0) 
                col1 = 0;
            for(int j = 1; j < m; j++){
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }
        
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j > 0; j--){
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            if(col1 == 0) matrix[i][0] = 0;
        }
    }
};
