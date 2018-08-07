// https://leetcode.com/problems/target-sum/description/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S, int i = 0) {
        int ans = 0, n = nums.size();
        if (n == i) return S == 0;
        ans += findTargetSumWays(nums, S - nums[i], i + 1) + findTargetSumWays(nums, S + nums[i], i + 1);
        return ans;
    }
};
