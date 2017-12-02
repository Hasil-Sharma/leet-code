// https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));
        
        for(int i = 1; i <= n; i++){
            dp[i][i] = 0;
            if (i != n)
            dp[i][i+1] = i;
        }
        
        for(int e = 2; e <= n; e++){
            for(int s = e - 1; s > 0; s--){
                for(int k = s + 1; k < e; k++){
                    dp[s][e] = min(dp[s][e], k + max(dp[s][k - 1], dp[k + 1][e]));
                }
            }
        }
        
        return dp[1][n];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().getMoneyAmount(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
