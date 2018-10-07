// https://leetcode.com/problems/search-a-2d-matrix/description/

class Solution {
public:
    
    pair<int, int> getij(int mid, int n){
        int j = mid % n, i = (mid - j) / n;
        return {i, j};
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        if (m == 0 || n == 0) return false;
        
        int s = 0, e = m*n - 1;
        
        while(e >= s){
            int mid = s + (e - s)/2;
            pair<int, int> ij = getij(mid, n);
            int diff = target - matrix[ij.first][ij.second];
            if (diff == 0) return true;
            else if (diff > 0) s = mid + 1;
            else e = mid - 1;
        }
        
        return false;
    }
};
