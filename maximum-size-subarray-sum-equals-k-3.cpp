// https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/description/

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> preSum;
        int p = 0, ans = 0;
        preSum[0] = -1;
        
        for(int i = 0; i < nums.size(); i++){
            p += nums[i];
            if (preSum.count(p - k)) ans = max(ans, i - preSum[p - k]);
            if (!preSum.count(p)) preSum[p] = i;
        }
        
        return ans;
    }
};
