// https://leetcode.com/problems/longest-valid-parentheses/description/

class Solution {
public:
    int longestValidParentheses(string s) {
        return max(helper(s, '('), helper(s, ')'));
    }
    
    int helper(string& s, char c){
        int length = 0, longest = 0, extra = 0, n = s.length();
        
        for(int i = (c == ')' ? n - 1 : 0); c == ')' ? i >= 0 : i < n; c == ')' ? i-- : i++){
            if (s[i] == c){
                length++;
                extra++;
            } else {
                if (extra > 0){
                    extra--;
                    length++;
                    if (extra == 0){
                        longest = max(longest, length);
                    }
                } else {
                    extra = 0;
                    length = 0;
                }
            }
        }
        return longest;
    }
};
