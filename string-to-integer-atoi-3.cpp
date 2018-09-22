// https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string str) {
        bool sign = false;
        int i = 0, n = str.length(), ans = 0;
        while(i < n && str[i] == ' ') i++;
        
        if (i < n && (str[i] == '+' || str[i] == '-')) sign = (str[i++] == '-');
        
        while(i < n && '0' <= str[i] && str[i] <= '9'){
            if (ans > INT_MAX/10 || (ans == INT_MAX/10 && str[i] - '0' > INT_MAX % 10))
                return sign ? INT_MIN : INT_MAX;
            
            ans = ans * 10 + str[i] - '0';
            i++;
        }
        
        return sign ? -ans : ans;
    }
};
