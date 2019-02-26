// https://leetcode.com/problems/word-break/description/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.length() == 0) return true;
        if (dp.count(s)) return dp[s];
        
        for(auto str: wordDict){
            if (s.find(str) == 0 && wordBreak(s.substr(str.length()), wordDict))
                return dp[s] = true;
        }
        
        return dp[s] = false;
    }
    
private:
    unordered_map<string, bool> dp;
};
