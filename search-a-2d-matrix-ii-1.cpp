// https://leetcode.com/problems/search-a-2d-matrix-ii/description/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0, low = 0, high = n - 1;
        if (m == 0 || n == 0)
            return false;
        
        for(int i = 0; i < m; i++){
            if (matrix[i][0] > target)
                break;
            low = 0;
            high = n - 1;
            while(low <= high){
                int mid = low + (high - low) / 2;
                if (matrix[i][mid] > target) high = mid - 1;
                else if (matrix[i][mid] < target) low = mid + 1;
                else return true;
            }
        }
        
        return false;
    }
};
