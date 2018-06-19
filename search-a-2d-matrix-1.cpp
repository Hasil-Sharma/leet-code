// https://leetcode.com/problems/search-a-2d-matrix/description/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        
        if(m == 0 || n == 0)
            return false;
        
        int low = 0, high = m * n - 1;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            int val = matrix[mid / n][mid - (mid / n)*n];
            if ( val > target) high = mid - 1;
            else if (val < target) low = mid + 1;
            else return true;
        }
        return false;
    }
};
