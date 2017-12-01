// https://leetcode.com/problems/knight-probability-in-chessboard/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValid(int N, int r, int c){
        return r < N && c < N && r >= 0 && c >= 0;
    }
    
    double helper(int N, int K, int r, int c, int k, vector<vector<vector<double>>>& dp){
       if(this->checkValid(N, r, c)){
           if (dp[r][c][k] != -1.0) return dp[r][c][k];
           else if (k == K) return 1.0;
           else {
               dp[r][c][k] = 0.0;
               for(int i = -2; i <= 2; i++){
                   if (i == 0) continue;
                   dp[r][c][k] += this->helper(N, K, r + i, c + 3 - abs(i), k + 1, dp) + 
                       this->helper(N, K, r + i, c - (3 - abs(i)), k + 1, dp);
               }
               return dp[r][c][k];
           }
       } else return 0.0;
    }
    double knightProbability(int N, int K, int r, int c) {
        vector< vector< vector<double>>> dp(N, vector<vector<double>>(N, vector<double>(K + 1, -1.0)));
        dp[r][c][0] = this->helper(N, K, r, c, 0, dp);
        // Finding total number of possible moves to make K moves and still be on board
        return dp[r][c][0] / pow(8, K);
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int N = stringToInteger(line);
        getline(cin, line);
        int K = stringToInteger(line);
        getline(cin, line);
        int r = stringToInteger(line);
        getline(cin, line);
        int c = stringToInteger(line);
        
        double ret = Solution().knightProbability(N, K, r, c);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
