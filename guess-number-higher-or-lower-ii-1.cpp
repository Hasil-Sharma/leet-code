// https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int helper(int s, int e, vector<vector<int>>& dp){
        if (s >= e) return 0;
        else if (dp[s][e] != INT_MAX) return dp[s][e];
        for(int i = s; i <= e; i++){
            dp[s][e] = min(dp[s][e], i + max(this->helper(s, i - 1, dp), this->helper(i + 1, e, dp)));
        }
        return dp[s][e];
    }
    
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        dp[1][n] = this->helper(1, n, dp);
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
