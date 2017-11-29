//https://leetcode.com/problems/ones-and-zeroes/discuss/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findMaxForm(vector<string>& strs, int m, int n) {
            int ans = 0, m_s, n_s, dp[m+1][n+1];
            memset(dp, 0, sizeof(dp[0][0]) * (m + 1) * (n + 1));
            for(auto &str: strs){
                m_s = count(str.begin(), str.end(), '0'); // number of zeroes in str
                n_s = count(str.begin(), str.end(), '1'); // number of ones in str
                for(int i = m; i >= m_s; i--)
                    for(int j = n; j >= n_s; j--){
                        dp[i][j] = max(dp[i][j], 1 +  dp[i - m_s][j - n_s]);
                    }
            }
            return dp[m][n];
        }
};

