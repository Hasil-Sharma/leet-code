// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

class Solution {
public:
    bool checkOperator(string c){
        return (c.size() == 1 && (c[0] == '+' || c[0] == '-' || c[0] == '*' || c[0] == '/')) ? true : false;
    }
    
    void applyOperator(char opt, stack<int>& stk){
        int a, b, ans;
        a = stk.top(); stk.pop();
        b = stk.top(); stk.pop();
        
        switch(opt){
            case '+': ans = a + b; break;
            case '-': ans = b - a; break;
            case '*': ans = a * b; break;
            case '/': ans = b / a; break;
        }
        stk.push(ans);
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(string& token: tokens){
            if (checkOperator(token)) applyOperator(token[0], stk);
            else stk.push(stoi(token));
        }
        return stk.top();
    }
};
