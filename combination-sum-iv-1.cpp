// https://leetcode.com/problems/combination-sum-iv/description/

class Solution {
public:
    
    unordered_map<int, int> dp;
    int combinationSum4(vector<int>& nums, int target) {
        
        if (target <= 0) return target == 0;
        else if (dp.count(target)) return dp[target];
        
        int ans = 0;
        for(int num : nums){
            ans += combinationSum4(nums, target - num);
        }
        dp[target] = ans;
        return ans;
    }
};
