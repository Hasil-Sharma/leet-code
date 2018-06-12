// https://www.lintcode.com/problem/flip-game/description

class Solution {
public:
    /**
     * @param s: the given string
     * @return: all the possible states of the string after one valid move
     */
    vector<string> generatePossibleNextMoves(string &s) {
        // write your code here
        vector<string> ans;
        int start = 1;
        
        while(start < s.length()){
            if (s[start] == '+' && s[start - 1] == '+'){
                ans.push_back(s);
                ans.back()[start] = '-';
                ans.back()[start - 1] = '-';
            }
            start++;
        }
        
        return ans;
    }
};
