//https://leetcode.com/problems/move-zeroes/description/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int insertIndex = 0;
        
        for(int num: nums){
            if (num != 0) nums[insertIndex++] = num;
        }
        
        while(insertIndex < nums.size())
            nums[insertIndex++] = 0;
        
    }
};
