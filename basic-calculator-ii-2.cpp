// https://leetcode.com/problems/basic-calculator-ii/description/

class Solution {
public:
    int calculate(string s) {
        char c = 0;
        int num = 0, ans = 0, l = s.length(), prev = 0;
        
        for(int i = 0; i <= l; i++){
            if (i < l && s[i] == ' ') continue;
            else if (i < l && s[i] <= '9' && s[i] >= '0')
                num = num * 10 + s[i] - '0';
            else {
                if (c == '+') {
                    ans += num; prev = num;
                } else if (c == '-') {
                    ans -= num; prev = -num;
                } else if (c == '*' || c == '/'){
                    ans = ans - prev + (c == '*' ? prev * num : prev / num);
                    prev = (c == '*' ? prev * num : prev / num);
                } else {
                    prev = num;
                    ans = num;
                }
                c = s[i];
                num = 0;
            }
        }
        
        return ans;
    }
};
