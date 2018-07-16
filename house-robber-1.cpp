// https://leetcode.com/problems/house-robber/description/

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
vpii steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        vi dp(n, -1);
        
        dp[n-1] = nums[n-1];
        dp[n-2] = nums[n-2];
        
        return max(helper(nums, dp, 0), helper(nums, dp, 1));
    }
    
    int helper(vi& nums, vi& dp, int index){
        int n = nums.size();
        
        if (index >= n) return 0;
        else if (dp[index] >= 0) return dp[index];
        
        for(int i = index + 2; i < n; i++)
            dp[index] = max(dp[index], nums[index] + helper(nums, dp, i));
        
        return dp[index];
    }
};
