
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vvi dp = vvi(n, vi(n, - 1));
            
        dp[0][n-1] = helper(s, wordDict, dp, 0, n - 1);
        
        return dp[0][n-1] == 1;
    }
    
    
    int helper(string& s, vs& dict, vvi& dp, int i, int j){
        if (i == s.length()) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        
        dp[i][j] = 0;
        for(string word : dict){
            if (s.find(word, i) == i){
                dp[i][j] = dp[i][j] || helper(s, dict, dp, i + word.length(), j);
            }
        }
        
        return dp[i][j];
    }
};
