// https://leetcode.com/problems/letter-case-permutation/description/

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        int l = S.length();
        vector<string> ans;
        helper(ans, 0, l, S);
        return ans;
    }
    
    void helper(vector<string>& ans, int idx, int l, string& s){
        if (idx >= l){
            ans.push_back(s);
            return;
        }
        
        while(!isalpha(s[idx]) && idx < l)
            idx++;
        
        helper(ans, idx + 1, l, s);
        if (idx < l){
            s[idx] = toggle_case(s[idx]);
            helper(ans, idx + 1, l, s);
            s[idx] = toggle_case(s[idx]);
        }
    }
    
    char toggle_case(char c){
        return c == toupper(c) ? tolower(c) : toupper(c);
    }
};
