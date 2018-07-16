// https://leetcode.com/problems/maximum-length-of-pair-chain/description/

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

bool operator< (const vi& v1, const vi& v2){
    return v1[1] < v2[0];
}
class Solution {
public:
    
    struct customCmp {
        inline bool operator() (const vi& p1, const vi& p2) {
            return p1[0] != p2[0] ? p1[0] < p2[0]: p1[1] < p2[1]; 
        }
    };
    
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size(), ans = 0;
        sort(pairs.begin(), pairs.end(), customCmp());
        
        vi dp(n, -1);
        
        for(int i = 0; i < n; i++)
            ans = max(ans, helper(pairs, dp, i));
        return ans;
    }
    
    int helper(vvi& pairs, vi& dp, int idx){
        if (idx == pairs.size()) return 0;
        else if (dp[idx] != -1) return dp[idx];
        
        dp[idx] = 1;
        
        for(int i = idx; i < pairs.size(); i++)
            dp[idx] = pairs[idx] < pairs[i] ? max(dp[idx], 1 + helper(pairs, dp, i)) : dp[idx];
        
        return dp[idx];
    }
};
