// https://leetcode.com/problems/wildcard-matching/description/

class Solution {
public:
    vector<vector<int>> dp;
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        dp = vector<vector<int>>(n + 1, vector<int>(m + 1, - 1));
        return helper(s, p, 0 ,0);
    }
    bool helper(string& s, string& p, int i, int j){
        if (j == p.length()) return i == s.length();
        else if (dp[i][j] != -1) return dp[i][j];
        // match single letter in starting of p and s
        else if (i < s.length() && (s[i] == p[j] || p[j] == '?')) return dp[i][j] = helper(s, p, i + 1, j + 1);
        // match single letter and keep '*'
        // do not match letter and skip '*'
        // match a single letter and skip '*'
        else if (p[j] == '*') 
            return dp[i][j] = (i < s.length()  && helper(s, p, i + 1, j)) || helper(s, p, i, j + 1) || (i < s.length() && helper(s, p, i + 1, j + 1));
        return dp[i][j] == 1;
    }
};
