// https://leetcode.com/problems/combination-sum-iv/description/

class Solution {
public:
    unordered_map<int, int> dp;
    
    int combinationSum4(vector<int>& nums, int target) {
        return nums.size() > 0 ? helper(nums, target)  : target == 0;
    }
    
    int helper(vector<int>& nums, int target){
        if (target <= 0) return target == 0;
        else if (dp.count(target)) return dp[target];
        
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++)
            ans += helper(nums, target - nums[i]);
        
        return dp[target] = ans;
    }
};
