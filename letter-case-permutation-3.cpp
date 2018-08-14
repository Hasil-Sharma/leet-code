// https://leetcode.com/problems/letter-case-permutation/description/

typedef vector<string> vs;
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vs ans;
        helper(S, 0, ans);
        return ans;
    }
    
    void helper(string& s, int i, vs& ans){
        while(i < s.length() && !isalpha(s[i])) i++;
        if (i == s.length()) {
            ans.push_back(s);
            return;
        }
        
        s[i] = tolower(s[i]);
        helper(s, i + 1, ans);
        s[i] = toupper(s[i]);
        helper(s, i + 1, ans);
    }
};
