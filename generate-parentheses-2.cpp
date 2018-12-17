// https://leetcode.com/problems/generate-parentheses/description/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<char> temp(2*n);
        vector<string> ans;
        if (n > 0)
        helper(ans, temp, 0, 2*n);
        return ans;
    }
    
    void helper(vector<string>& ans, vector<char>& temp, int idx, int len){
        if (idx == len && isValid(temp))
            ans.push_back(string(temp.begin(), temp.end()));
        else if (idx == len) return;
        else {
            for(char bkt : bkts){
                temp[idx] = bkt;
                helper(ans, temp, idx + 1, len);
            }
        }
    }
    
    bool isValid(vector<char>& temp){
        stack<char> stk;
        
        for(char c : temp){
            if (c == ')' && stk.empty()) return false;
            else if (c == ')') stk.pop();
            else stk.push(c);
        }
        
        return stk.empty();
    }
    
private:
    vector<char> bkts = {'(', ')'};
};
