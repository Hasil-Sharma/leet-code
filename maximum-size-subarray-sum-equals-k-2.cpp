// https://www.lintcode.com/problem/maximum-size-subarray-sum-equals-k/description

class Solution {
public:
    /**
     * @param nums: an array
     * @param k: a target value
     * @return: the maximum length of a subarray that sums to k
     */
    int maxSubArrayLen(vector<int> &nums, int k) {
        // Write your code here
        std::unordered_map<int, int> sumhash;
        
        sumhash[0] = -1;
        int r = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            r += nums[i];
            if (sumhash.count(r - k))
            ans = max(ans, i - sumhash[r - k]);
            if (!sumhash.count(r))
            sumhash[r] = i;
        }
        return ans;
    }
};
