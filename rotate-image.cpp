// https://leetcode.com/problems/rotate-image/description/

class Solution {
    typedef vector<vector<int>> vvi;
public:
    void helper(vvi& matrix, int s1, int e1, int s2, int e2){
        
        // printf("Start: (%d %d) (%d %d)\n", s1, e1, s2, e2);
        // Clockwise swap elements one by once : between consecutive orthogonal rows and columns
        for(int i = 0; i < s2 - s1; i++){
            // moving along the row and column with index: i
            swap(matrix[s1][e1 + i], matrix[s1 + i][e2]);
            // printf("(%d %d) (%d %d)\n", s1, e1 + i, s1 + i, e2);

            swap(matrix[s1][e1 + i], matrix[s2][e2 - i]);
            // printf("(%d %d) (%d %d)\n", s1, e1 + i, s2,  e2 - i);

            swap(matrix[s1][e1 + i], matrix[s2 - i][e1]);
            // printf("(%d %d) (%d %d)\n", s1, e1 + i, s2 - i, e1);

        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Going Layer by Layer
        for(int i = 0; i < n / 2; i++){
            helper(matrix, i, i, n - i - 1, n - i - 1);
        }
    }
};
