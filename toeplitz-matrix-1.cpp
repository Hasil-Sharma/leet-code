// https://leetcode.com/problems/toeplitz-matrix/description/

class Solution {
public:
    
    bool helper(vector<vector<int>>& matrix, bool row){
        int M = matrix.size(), N = matrix[0].size();
        bool flag = true;
        
        for(int i = 0; i < (row ? M : N) && flag; i++){
            pair<int, int> index = row ? make_pair(i, 0) : make_pair(0, i);
            int num = matrix[index.first][index.second];
            while(index.first < M && index.second < N && flag) {
                flag = (num == matrix[index.first][index.second]) ? true : false;
                index.first++;
                index.second++;
            }
        }
        
        return flag;
    }
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        return helper(matrix, true) && helper(matrix, false);
    }
};
