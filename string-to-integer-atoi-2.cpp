// https://leetcode.com/problems/string-to-integer-atoi/description/

class Solution {
public:
    int myAtoi(string s) {
        bool sign = false;
        int i = 0, n = s.length();
        int ans = 0;
        
        while(i < n && (s[i] == ' '))
            i++;
        
        if (s[i] == '+' || s[i] == '-')
            sign = s[i++] == '-';
        
        while('0' <= s[i] && s[i] <= '9' && i < n){
            int c = s[i++] - '0';
            
            // check if addition of number will cause an overflow
            if (INT_MAX / 10 < ans || (INT_MAX / 10 == ans && INT_MAX % 10 < c))
                return sign ? INT_MIN : INT_MAX;
            
            ans = ans * 10 + c;
        }
        
        return sign ? -ans : ans;
    }
};
