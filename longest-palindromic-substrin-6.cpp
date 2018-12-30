// https://leetcode.com/problems/longest-palindromic-substring/description/

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) return "";
        
        int idx = 0, len = 1, n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        for(int i = 0; i < n; i++)
            dp[i][i] = true;
        
        for(int i = 1; i < n; i++){
            dp[i-1][i] = s[i-1] == s[i];
            len = max(len, 1 + dp[i-1][i]);
            idx = dp[i-1][i] ? i-1 : idx;
        }
        
        for(int l = 3; l <= n; l++){
            for(int i = 0; i < n - l + 1; i++){
                int j = i + l - 1;
                if (dp[i+1][j-1] && s[i] == s[j]){
                    dp[i][j] = true;
                    len = l;
                    idx = i;
                }
            }
        }
        
        return s.substr(idx, len);
    }
};
