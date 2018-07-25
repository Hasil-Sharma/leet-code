// https://www.lintcode.com/problem/letter-case-permutation/description

class Solution {
public:
    /**
     * @param S: a string
     * @return: return a list of strings
     */
    vector<string> letterCasePermutation(string &S) {
        // write your code here
        vector<string> ans;
        int n = S.length();
        // if (n == 0) return ans;
        dfs(S, n, 0, ans);
        return ans;
    }
    
    void dfs(string& s, int n, int start, vector<string>& ans){
        if (start >= n) ans.push_back(s);
        else {
            while(start < n && !isalpha(s[start])) 
                start++;
            
            // without any change;
            dfs(s, n, start + 1, ans);
            if (start >= n) 
                return;
            if (isupper(s[start])) {
                s[start] = tolower(s[start]);
                dfs(s, n, start + 1, ans);
                s[start] = toupper(s[start]);
            } else {
                s[start] = toupper(s[start]);
                dfs(s, n, start + 1, ans);
                s[start] = tolower(s[start]);
            }
        }
    }
};
