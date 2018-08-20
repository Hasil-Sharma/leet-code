// https://leetcode.com/problems/continuous-subarray-sum/description/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> preSum;
        int p = 0;
        preSum[0] = -1;
        
        for(int i = 0; i < nums.size(); i++){
            p = k ? (p + nums[i]) % k : p + nums[i];
            if (preSum.count(p) && i - preSum[p] > 1)
                return true;
            if (!preSum.count(p))
                preSum[p] = i;
        }
        
        return false;
    }
};
