// https://leetcode.com/problems/minimum-size-subarray-sum/description/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int rSum = nums[0];
        int ans = rSum >= s ? 1 : INT_MAX, start = 0, end = 1;
        while(start != end && end < nums.size()){
            ans = (rSum += nums[end++]) >= s ? min(ans, end - start) : ans;            
            while(rSum - nums[start] >= s){
                rSum -= nums[start++];
                ans = min(ans, end - start);
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
