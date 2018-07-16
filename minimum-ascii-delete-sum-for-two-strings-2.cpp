// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/

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
    
    int strToVal(string& s){
        int ans = 0;
        for(char c : s)
            ans += c;
        return ans;
    }
    
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        vvi dp(m + 1, vi(n + 1, 0));
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if (s1[i-1] == s2[j-1]) dp[i][j] = s1[i-1] + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return strToVal(s1) + strToVal(s2) - 2*dp[m][n];
    }
};
