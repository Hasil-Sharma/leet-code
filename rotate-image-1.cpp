// https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = n ? matrix[0].size() : 0;
        reverse(matrix.begin(), matrix.end());
        
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < m; j++)
                swap(matrix[i][j], matrix[j][i]);
    }
};
