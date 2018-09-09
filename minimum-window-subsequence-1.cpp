// https://leetcode.com/problems/minimum-window-subsequence/description/

class Solution {
public:
    string minWindow(string S, string T) {
        int m = S.length(), n = T.length();
        vector<vector<int>> dp(m , vector<int>(n, -1));
        
        for(int i = 0; i < m; i++)
            if (S[i] == T[0])
                dp[i][0] = i;
        
        for(int j = 1; j < n; j++){
            int k = -1;
            for(int i = 0; i < m; i++){
                if (S[i] == T[j])
                    dp[i][j] = k;
                k = max(k, dp[i][j-1]);
            }
        }
        
        int len = INT_MAX, start = -1;
        for(int i = 0; i < m; i++){
            if (dp[i][n-1] != -1 && i - dp[i][n-1] + 1 < len){
                len = i - dp[i][n-1] + 1;
                start = dp[i][n-1];
            }
        }
        
        return start == -1 ? "" : S.substr(start, len);
    }
};
