// https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> matching = {{')', '('}, {'}', '{'}, {']', '['}};
        for(char c : s){
            if (matching.count(c)) {
                if (stk.empty() || stk.top() != matching[c]) 
                    return false;
                stk.pop();
            } else stk.push(c);
        }
        
        return stk.empty();
    }
};
