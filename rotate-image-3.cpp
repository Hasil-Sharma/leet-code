// https://leetcode.com/problems/rotate-image/description/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = n ? matrix[0].size() : 0, i = 0;
        
        while(i < n - 1 - i){
            swap(matrix[i], matrix[n - 1 - i]);
            i++;
        }
        
        for(int i = 0; i < n; i++){
            for(int j = i; j < m; j++)
                swap(matrix[i][j], matrix[j][i]);
        }
        
    }
};
