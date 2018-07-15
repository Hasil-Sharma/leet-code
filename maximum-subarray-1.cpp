// https://leetcode.com/problems/maximum-subarray/description/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), ans = n ? nums[0] : 0;
        if(!n) return ans;
        int currSum = 0;
        
        for(int i = 0; i < n; i++){
            currSum += nums[i];
            if (currSum < 0) {
                currSum = 0;
                ans = max(ans, nums[i]);
            } 
            else ans = max(ans, currSum);
        }
        return ans;
    }
};
