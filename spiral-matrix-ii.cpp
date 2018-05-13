// https://leetcode.com/problems/spiral-matrix-ii/description/

class Solution {
public:
    void fill(vector<vector<int>>& ans, int start, int size, int &value){
        
        // going left to right
        for(int i = start; i < size - start; i++)
            ans[start][i] = value++;
        
        // going top to bottom
        for(int i = start + 1; i < size - start; i++)
            ans[i][size - start - 1] = value++;
        
        // going right to left
        for(int i = size - start - 2; i >= start; i--)
            ans[size - start - 1][i] = value++;
        
        // going from bottom to top
        for(int i = size - start - 2; i > start; i--)
            ans[i][start] = value++;
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> answer(n , vector<int>(n, 0));
        int val = 1;
        for(int i = 0; i < n ; i++){
            if (answer[i][i] != 0)
                break;
            fill(answer, i, n, val);
        }
        return answer;
    }
};
