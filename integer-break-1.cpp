// https://leetcode.com/problems/integer-break/description/

#define mp(A, B) make_pair(A, B)
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef stack<int> stki;
typedef queue<int> qi;
typedef deque<int> dqi;
typedef unordered_map<int, int> mpii;

class Solution {
public:
    int integerBreak(int n) {
        if (n < 4) return n - 1;
        
        vi dp(n+1, 0);
        
        for(int i = 1; i <= n; i++){
            if (i < 4) 
                dp[i] = i;
            else
            for(int j = 1; j <= i/2; j++)
            dp[i] = max(dp[i], dp[j] * dp[i - j]);
        }
            
        
        return dp[n];
    }
};
