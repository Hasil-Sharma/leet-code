// https://leetcode.com/problems/longest-valid-parentheses/description/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        
        stk.push(-1);
        
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            if (c == ')' && !stk.empty() && s[stk.top()] == '(')
                stk.pop();
            else stk.push(i);
        }
        
        int j = s.length() - 1, ans = 0;
        
        while(!stk.empty()) {
            int i = stk.top();
            stk.pop();
            ans = max(ans, j - i); // everything after i till j is valid
            j = i - 1;
        }
        
        return ans;
    }
};
