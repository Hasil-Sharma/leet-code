// https://leetcode.com/problems/range-sum-query-immutable/description/

typedef vector<int> vi;
class NumArray {
public:
    vi sumArray;
    NumArray(vector<int> nums) {
        int n = nums.size();
        sumArray.resize(n);
        for(int i = 0; i < n; i++)
            sumArray[i] = nums[i] + (i > 0 ? sumArray[i-1] : 0);
    }
    
    int sumRange(int i, int j) {
        return sumArray[j] - (i > 0 ? sumArray[i-1] : 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
