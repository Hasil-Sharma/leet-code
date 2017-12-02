// https://leetcode.com/problems/perfect-squares/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int index = 2, next_sqr = 4, curr_sqr = 1;
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++){
            if (i == next_sqr){
                dp[i] = 1;
                index++;
                curr_sqr = next_sqr;
                next_sqr = index * index;
            } else {
                for(int j = 1; j*j <= curr_sqr; j++)
                    dp[i] = min(dp[i - j*j] + dp[j*j], dp[i]);
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
        
        int ret = Solution().numSquares(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
