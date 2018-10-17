// https://leetcode.com/problems/maximum-subarray/description/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), ans, curr;
        if (n == 0) return 0;
        
        curr = nums[0];
        ans = nums[0];
        
        for(int i = 1; i < n; i++){
            curr = nums[i] + (curr > 0 ? curr : 0);
            ans = max(curr, ans);
        }
        
        return ans;
    }
};
