// https://leetcode.com/problems/maximum-subarray/description/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], sum = 0;
        
        for(int num : nums){
            sum += num;
            ans = max(ans, sum);
            sum = max(sum, 0);
        }
        
        return ans;
    }
};
