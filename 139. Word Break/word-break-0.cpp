// https://leetcode.com/problems/word-break/description/
class Solution {
public:
    void helper(string& s, unordered_map<string, bool>& hashMap, vector<vector<int>>& dp, int i, int j){
        if (dp[i][j] != -1 || i > j) return;
        
        // getting substring for given i and j
        string temp = s.substr(i, j - i + 1);
        
        // checking if temp is in hashMap
        if (hashMap.find(temp) != hashMap.end()){
            dp[i][j] = 1;
        } else {
            for(int k = i; k < j; k++){
                // breaking into two parts i to k and k + 1 to j
                helper(s, hashMap, dp, i, k);
                if (dp[i][k] == 1){
                    helper(s, hashMap, dp, k + 1, j);
                    if (dp[k+1][j] == 1) {
                        dp[i][j] = 1;
                    }
                }
            }
            if (dp[i][j] == -1) dp[i][j] = 0;
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_map<string, bool> hashMap;
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        for(string str: wordDict){
            hashMap[str] = true;
        }
        
        helper(s, hashMap, dp, 0, n - 1);
        
        return dp[0][n-1] == 1 ? true : false;
    }
};
