// https://leetcode.com/problems/unique-paths/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m+1][n+1];
        
        for(int i = 1; i <= m; i++)
            dp[i][1] = 1;
        
        for(int i = 1; i <= n; i++)
            dp[1][i] = 1;
        
        for(int i = 2; i <= m; i++){
            for(int j = 2; j <= n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
        return dp[m][n];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        int ret = Solution().uniquePaths(m, n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
