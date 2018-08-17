// https://leetcode.com/problems/wildcard-matching/description/

class Solution {
public:
    vector<vector<int>> dp;
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        dp = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));
        dp[0][0] = helper(s, p, 0, 0, m, n);
        return dp[0][0];
    }
    
    bool helper(string& s, string& p, int i, int j, int m, int n){
        if (j == n)  return i == m; // pattern has been used completely
        else if (dp[i][j] != -1) 
            return dp[i][j];
        else if (i < m && (p[j] == '?' || p[j] == s[i])) // there are characters to match
            dp[i][j] = helper(s, p, i + 1, j + 1, m, n);
        else if (p[j] == '*') 
            dp[i][j] = (i < m ? helper(s, p, i + 1, j, m, n) : false) || helper(s, p, i, j + 1, m, n);
        else 
            dp[i][j] = 0;
        return dp[i][j];
    }
};
