// https://leetcode.com/problems/remove-invalid-parentheses/description/

typedef vector<string> vs;
typedef vector<int> vi;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> mp;
        vector<string> ans;
        queue<string> q;
        q.push(s);
        while(!q.empty()){
            s = q.front();
            q.pop();
            if (mp.count(s)) continue;
            mp.insert(s);
            if (isValid(s)){
                ans.push_back(s);
            } else if (ans.size() == 0) {
                for(int i = 0; i < s.length(); i++){
                    if (s[i] == '(' || s[i] == ')' && (i == s.length() - 1 || s[i] != s[i+1]))
                            q.push(s.substr(0, i) + s.substr(i + 1));
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
