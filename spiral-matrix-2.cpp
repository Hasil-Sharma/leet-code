// https://leetcode.com/problems/spiral-matrix/description/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        vector<int> ans;
        if (!m) return ans;
        int r1 = 0, c1 = 0, r2 = m - 1, c2 = n - 1;
        
        while(ans.size() != m * n){
            for(int i = c1; i <= c2; i++)
                ans.push_back(matrix[r1][i]);
            
            for(int j = r1 + 1; j <= r2; j++)
                ans.push_back(matrix[j][c2]);
            
            if (r1 < r2 && c1 < c2){
                for(int i = c2 - 1; i >= c1; i--)
                    ans.push_back(matrix[r2][i]);

                for(int j = r2 - 1; j > r1; j--)
                    ans.push_back(matrix[j][c1]);
            }
            
            r1++; c1++;
            r2--; c2--;
        }
        
        return ans;
    }
};
