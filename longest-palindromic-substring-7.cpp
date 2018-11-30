// https://leetcode.com/problems/longest-palindromic-substring/description/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), start = 0, length = 1;
        vector< vector<bool>> dp(n, vector<bool>(n, false));
        
        for(int i = 0; i < n; i++)
            dp[i][i] = true;
        
        for(int i = 1; i < n; i++)
            if(s[i - 1] == s[i]){
                start = i - 1;
                dp[i-1][i] = true;
                length = 2;
            }
        
        
        for(int k = 3; k <= n; k++){
            for(int i = 0; i <= n - k; i++){
                int j = i + k - 1;
                if (s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = dp[i+1][j-1];
                    start = i;
                    length = k;
                }
            }
        }
        
        return s.substr(start, length);
        
    }
};
