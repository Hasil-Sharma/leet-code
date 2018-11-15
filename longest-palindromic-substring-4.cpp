// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), start = 0, len = 1;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        for(int i = 0; i < n; i++)
            dp[i][i] = true;
        
        for(int i = 0; i < n - 1; i++){
            if (s[i] == s[i+1]){
                dp[i][i+1] = true;
                start = i;
                len = 2;
            }
        }
        
        for(int k = 3; k <= n; k++){
            for(int i = 0; i <= n - k; i++){
                int j = i + k - 1;
                
                if(dp[i+1][j-1] && s[i] == s[j]){
                    dp[i][j] = true;
                    start = i;
                    len = k;
                }
            }
        }
        
        return s.substr(start, len);
    }
};
