// https://leetcode.com/problems/strobogrammatic-number/description/

class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> mapping = {
            {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}
        };
        
        int i = num.size() - 1;
        
        for(char c : num){
            if (!mapping.count(c)) return false;
            else if (mapping[c] != num[i--]) return false;
        }
        
        return true;
    }
};
