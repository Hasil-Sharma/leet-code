// https://leetcode.com/problems/word-break/description/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        unordered_set<string> hashSet(wordDict.begin(), wordDict.end());
        
        for(int i = 1; i <= n; i++){
            for(int j = 0 ; j < i; j++){
                if (dp[j] && hashSet.count(s.substr(j, i - j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
