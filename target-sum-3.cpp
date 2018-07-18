// https://leetcode.com/problems/target-sum/description/

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
typedef queue<pair<int, int>> qpii;
typedef unordered_map<int, int> umpii;
typedef set<int> si;
vpii steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    umpii dp;
    int getKey(int idx, int S){
        return 1001 * S + idx;
    }
    int findTargetSumWays(vector<int>& nums, int S, int idx = 0) {
        if (idx == nums.size()){
            return S == 0;
        }
        
        int key = getKey(idx, S);
        if (!dp.count(key))
        dp[key] = findTargetSumWays(nums, S - nums[idx], idx + 1) + findTargetSumWays(nums, S + nums[idx], idx + 1);
        return dp[key];
    }
};
