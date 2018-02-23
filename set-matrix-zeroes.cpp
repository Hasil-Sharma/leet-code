// https://leetcode.com/problems/set-matrix-zeroes/description/

class Solution {
public:
    void nullifyCol(vector<vector<int>>& matrix, int i, int m){
        for(int j = 0; j < m; j++)
            matrix[j][i] = 0;
    }
    
    void nullifyRow(vector<vector<int>>& matrix, int i, int n){
        for(int j = 0; j < n; j++)
            matrix[i][j] = 0;
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        
        // m is number of rows
        // n is number of columns
        
        int rows = matrix.size(), cols = rows > 0 ? matrix[0].size() : 0;
        bool rowHasZero = false, colHasZero = false;
        
        // check if first row has zero
        for(int i = 0; i < cols && !rowHasZero; i++)
            rowHasZero = matrix[0][i] == 0 ? true : false;
        
        // check if first column has zero
        for(int i = 0; i < rows && !colHasZero; i++)
            colHasZero = matrix[i][0] == 0 ? true : false;
        
        // reading rest of the matrix, and setting first column and first row to zero
        for(int i = 1; i < rows; i++)
            for(int j = 1; j < cols; j++)
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0; // first column
                    matrix[0][j] = 0; // first row
                }
        
        // nullifying columns via first row
        for(int i = 1; i < cols; i++)
            if (matrix[0][i] == 0) nullifyCol(matrix, i, rows);
        
        // nullifying rows via first column
        for(int i = 0; i < rows; i++)
            if (matrix[i][0] == 0) nullifyRow(matrix, i, cols);
        
        if (rowHasZero) nullifyRow(matrix, 0, cols);
        if (colHasZero) nullifyCol(matrix, 0, rows);
    }
};
