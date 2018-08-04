// https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        
        for(char c : s){
            if (isopen(c)) stk.push(c);
            else if (checkmatch(c, stk)) stk.pop();
            else return false;
        }
        
        return stk.empty();
    }
    
    bool isopen(char c){
        return c == '{' || c == '[' || c =='(' ? true : false;
    }
    
    bool checkmatch(char c, stack<char>& stk){
        if (stk.empty()) return false;
        else if (stk.top() == '{' && c == '}') return true;
        else if (stk.top() == '[' && c == ']') return true;
        else if (stk.top() == '(' && c == ')') return true;
        return false;
    }
};
