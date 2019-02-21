// https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, n = nums.size(), j = 0;
        
        while(i < n){
            if (nums[i] != 0)
                nums[j++] = nums[i];
            i++;
        }
        while(j < n)
            nums[j++] = 0;
    }
};
