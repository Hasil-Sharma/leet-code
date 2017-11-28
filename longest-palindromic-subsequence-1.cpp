// https://leetcode.com/problems/longest-palindromic-subsequence/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length(), dp[n+1][n+1];
        string t = s;
        reverse(t.begin(), t.end());
        memset(dp, 0, sizeof(dp[0][0]) * (n+1) * (n+1));
        
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dp[i][j] = (s[i-1] == t[j-1]) ? dp[i-1][j-1] + 1 : max(dp[i][j-1], dp[i-1][j]);
        return dp[n][n];
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().longestPalindromeSubseq(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
