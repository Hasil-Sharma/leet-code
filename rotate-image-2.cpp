// https://leetcode.com/problems/rotate-image/description/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        
        int n = matrix.size();
        
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
        }
    }
};
