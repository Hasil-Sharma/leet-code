// https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, n = nums.size(), j = 0;
        
        while(i < n)
            nums[i++] != 0 ? nums[j++] = nums[i-1] : -1;
        
        while(j < n)
            nums[j++] = 0;
    }
};
