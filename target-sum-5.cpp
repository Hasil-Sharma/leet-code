// https://leetcode.com/problems/target-sum/description/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S, int idx = 0) {
        if (idx == nums.size()) return S == 0;
        return findTargetSumWays(nums, S - nums[idx], idx + 1) + findTargetSumWays(nums,S + nums[idx], idx + 1);
    }
};
