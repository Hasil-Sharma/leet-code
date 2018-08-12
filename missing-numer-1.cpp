// https://leetcode.com/problems/missing-number/description/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = 0, n = nums.size();
        for(int i = 0; i < n; i++)
            x = (x ^ i ^ nums[i]);
        return x ^ n;
    }
};
