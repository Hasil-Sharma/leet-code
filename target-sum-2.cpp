// https://leetcode.com/problems/target-sum/description/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int ans = 0;
        helper(nums, ans, S, 0, 0);
        return ans;
    }
    
    void helper(vector<int>& nums, int& ans, int S, int tempSum, int idx){
        if (idx == nums.size()) {
            if (S == tempSum) ans++;
        } else{
            helper(nums, ans, S, tempSum + nums[idx], ++idx);
            helper(nums, ans, S, tempSum - nums[idx], idx);
        }
    }
};
