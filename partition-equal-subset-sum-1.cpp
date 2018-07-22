// https://leetcode.com/problems/partition-equal-subset-sum/description/

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
typedef unordered_set<int> usi;
vpii steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

template <typename T>
void printVec(T const& t){
    for(auto e :  t)
        cout << e << ",";
    cout << endl;
}

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        umpii dp;
        if (sum&1) return false;
        // odd sum array cannot be partitioned
        sort(nums.begin(), nums.end());
        return helper(nums, dp, sum / 2, 0);
    }
    
    bool helper(vi& nums, umpii& dp, int sum, int idx){
        if (sum == 0) return true;
        else if (idx == nums.size() || sum < 0) return false;
        int key = sum * 20001 + idx;
        if (dp.count(key))  return dp[key];
        bool flag = false;
        
        for(int i = idx; i < nums.size() && !flag; i++){
            flag = flag || helper(nums, dp, sum - nums[i], i + 1);
        }
        
        dp[key] = flag;
        return flag;
    }
};
