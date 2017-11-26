//https://leetcode.com/problems/integer-break/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        
        int dp[n+1];
        if (n == 2 || n == 3) return n - 1;
        memset(dp, 0, sizeof(dp));
        for(int i = 2; i <= n; i++){
            // Handling the case of 2 and 3
            if(i < 4) dp[i] = i;
            for(int j = 2; j <= i/2; j++){
                dp[i] = max(dp[i], j * dp[i - j]);
            }
        }
        
        return dp[n];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().integerBreak(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
