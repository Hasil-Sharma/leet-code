// https://leetcode.com/problems/combination-sum-iv/description/

class Solution {
public:    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp (target + 1, 0);
        
        for(int n : nums){
            if (n <= target)
            dp[n] = 1;
        }
        
        for(int i = 1; i <= target; i++){
            for(int j = 0; j < nums.size(); j++)
                dp[i] += (i - nums[j] >= 0) ? dp[i - nums[j]] : 0;
        }
        
        return dp[target];
    }
};
