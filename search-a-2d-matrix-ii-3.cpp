// https://leetcode.com/problems/search-a-2d-matrix-ii/description/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        if (!m || !n) return false;
        int i = 0, j = n - 1;
        
        while(i < m && j >= 0){
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
                j--;
            else i++;
        }
        
        return false;
    }
};
