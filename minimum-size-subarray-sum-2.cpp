// https://leetcode.com/problems/minimum-size-subarray-sum/description/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        vector<int> rSum(nums.size());
        vector<int> :: iterator itr;
        
        int temp = 0, ans = nums.size() ? (nums[0] >= s ? 1 : INT_MAX) : 0;
        for(int i = 0; i < nums.size(); i++)
            temp = (rSum[i] = nums[i] + temp);
        
        for(int i = 0; i < nums.size(); i++){
            if ((itr  = lower_bound(rSum.begin() + i, rSum.end(), s + rSum[i] - nums[i]))== rSum.end()) {
                ans = (i == 0) ? 0 : ans;
                break;
            }
            temp = itr - rSum.begin() - i + 1;
            ans = min(ans, temp);
        }
        return ans;
    }
};
