// https://leetcode.com/problems/string-to-integer-atoi/description/

class Solution {
public:
    int myAtoi(string str) {
        int i = 0, n = str.length(), ans = 0;
        bool neg = false;
        while(i < n && str[i] == ' ') i++;
        if (str[i] == '-' || str[i] == '+'){
            neg = (i < n && str[i] == '-');
            i++;
        }
        
        while(i < n && str[i] >= '0' && str[i] <= '9'){
            if (ans > INT_MAX/10 || ans == INT_MAX/10 && str[i] - '0' > INT_MAX%10)
                return neg ? INT_MIN : INT_MAX;
            ans = ans * 10 + str[i] - '0';
            i++;
        }
        
        return neg ? -ans : ans;
    }
};
