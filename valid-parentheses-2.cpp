// https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> matching = {
            {'}','{'}, 
            {')','('}, 
            {']','['}
        };
        unordered_map<char, int> openingCount = {{'{', 0}, {'[', 0}, {'(', 0}};
        stack<char> stk;
        
        for(char c : s){
            if (!openingCount.count(c)){
                if (stk.size() && stk.top() == matching[c]) stk.pop();
                else return false;
            } else stk.push(c);
        }
        
        return stk.empty();
    }
};
