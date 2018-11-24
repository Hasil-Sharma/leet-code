// https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), ans, curr;
        ans = curr = n ? nums[0] : 0;
        
        for(int i = 1; i < n; i++){
            curr = nums[i] + (curr > 0 ? curr : 0);
            ans = max(ans, curr);
        }
        
        return ans;
    }
};
