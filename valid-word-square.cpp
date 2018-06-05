// https://www.lintcode.com/problem/valid-word-square/description

class Solution {
public:
    /**
     * @param words: a list of string
     * @return: a boolean
     */
    bool validWordSquare(vector<string> &words) {
        // Write your code here
        int rows = words.size(), cols = words[0].length(), m, n;
        
        if (rows != cols){
            return false;
        }
        
        for(int i = 0; i < rows; i++){
            // compare ith row and ith column
            m = words[i].length();
            for(int j = 0; j < m; j++){
                if (i >= words[j].length() || words[i][j] != words[j][i]){
                    return false;
                }
            }
        }
        
        return true;
    }
};
