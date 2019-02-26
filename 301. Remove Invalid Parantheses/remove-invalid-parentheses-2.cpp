// https://leetcode.com/problems/remove-invalid-parentheses/description/

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        queue<pair<string, int>> q;
        int i;
        q.push({s, 0});
        
        while(!q.empty()){
            s = q.front().first; i = q.front().second; q.pop();
            if (isValid(s)) ans.push_back(s);
            else if (ans.size() == 0){
                for(int j = i; j < s.length(); j++){
                    if ((s[j] == '(' || s[j] == ')') && (j == i || s[j-1] != s[j])){
                        q.push({s.substr(0, j) + s.substr(j+1), j});
                    }
                }
            }
        }
        return ans;
    }
    
    bool isValid(string &s){
        int count = 0;
        for(char c : s){
            if (c == '(' || c == ')')
                count += c == '(' ? 1 : -1;
            if (count < 0) return false;
        }
        return count == 0;
    }
};
