// https://leetcode.com/problems/basic-calculator-ii/description/

class Solution {
public:
    int calculate(string s) {
        char c = 0;
        int num = 0, ans = 0, l = s.length();
        stack<int> stk;
        
        for(int i = 0; i <= l; i++){
            if (i < l && s[i] == ' ') continue;
            else if (i < l && s[i] <= '9' && s[i] >= '0')
                num = num * 10 + s[i] - '0';
            else {
                if (c == '+') {
                    stk.push(num);
                } else if (c == '-') {
                    stk.push(-num);
                } else if (c == '*' || c == '/'){
                    int n = stk.top(); stk.pop();
                    stk.push(c == '*' ? n * num : n / num);
                } else {
                    stk.push(num);
                }
                c = s[i];
                num = 0;
            }
        }
        
        while(!stk.empty()){
            ans += stk.top(); stk.pop();
        }
        return ans;
    }
};
