// https://leetcode.com/problems/range-sum-query-immutable/description/

class NumArray {
public:
    vector<int> preSum;
    int n;
    NumArray(vector<int> nums) {
        n = nums.size();
        if (!n) return;
        preSum = vector<int> (n, 0);
        preSum[0] = nums[0];
        for(int i = 1; i < n; i++)
            preSum[i] = preSum[i-1] + nums[i];
    }
    
    int sumRange(int i, int j) {
        return preSum[j] - preSum[i] + preSum[i] - (i > 0? preSum[i-1]: 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
