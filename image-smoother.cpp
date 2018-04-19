// https://leetcode.com/problems/image-smoother/description/

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int steps[][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
        vector<vector<int>> answer(M.size(), vector<int>(M[0].size(), 0));
        int n = M.size(), m = M[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int temp_sum = 0, temp_count = 0, p, q;
                
                for(int s = 0; s < 9; s++){
                    p = i + steps[s][0]; q = j + steps[s][1];
                    if (p > -1 && q > -1 && p < n && q < m){
                        temp_sum += M[p][q];
                        temp_count++;
                    }
                }

                answer[i][j] = temp_sum / temp_count;
            }
        }
        
        return answer;
    }
};
