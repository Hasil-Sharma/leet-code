// https://leetcode.com/problems/flipping-an-image/description/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        vector<vector<int>> answer(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++)
            for(int j = m - 1; j >= 0; j--)
                answer[i][m - 1 - j] = (!A[i][j]);
        
        return answer;
    }
};
