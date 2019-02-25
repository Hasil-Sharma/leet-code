// https://leetcode.com/problems/basic-calculator/

class Solution {
public:
    int calculate(string s) {
        int i = 0;
        auto ans = helper(s, i);
        return ans;
    }
    
    int helper(string &s, int& i){
        int n = s.length(), ans = 0;
        char sign = '+';
        if (n == 0 || i >= n) return 0;
        
        while(i < n && s[i] != ')'){
            char c = s[i++];
            if (c == ' ') continue;
            else if (c == '+' || c == '-') sign = c;
            else if (c == '(') {
                auto aa = helper(s, i);
                ans += (sign == '-' ? -aa : aa);
            } else {
                // it is a digit;
                int start = i - 1;
                int number = s[start] - '0';
                while(i < n && isdigit(s[i]))
                 number = number * 10 + (s[i++] - '0');
                ans += (sign == '-' ? -number : number);
            }
        }
        i++;
        return ans;
    }
};
