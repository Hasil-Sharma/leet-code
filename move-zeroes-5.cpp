// https://leetcode.com/problems/move-zeroes/description/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        
        while(j < n) {
            if(nums[j] != 0)
                nums[i++] = nums[j];
            j++;
        }
        
        while(i < n)
            nums[i++] = 0;
    }
};
