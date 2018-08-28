// https://leetcode.com/problems/string-to-integer-atoi/description/

class Solution {
public:
    int myAtoi(string s) {
        bool sign = false;
        int i = 0, n = s.length();
        long ans = 0;
        
        while(i < n && (s[i] == ' '))
            i++;
        
        if (s[i] == '+' || s[i] == '-')
            sign = s[i++] == '-';
        
        while('0' <= s[i] && s[i] <= '9' && i < n){
            int c = s[i++] - '0', prev = ans;
            ans = ans * 10 + c;
            
            if (ans > INT_MAX){
                ans = sign ? INT_MIN : INT_MAX;
                sign = false;
                break;
            }
        }
        
        return sign ? -ans : ans;
    }
};
