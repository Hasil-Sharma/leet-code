// https://leetcode.com/problems/move-zeroes/description/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        
        for(int num : nums){
            if (num) nums[i++] = num;
        }
        
        while(i < nums.size())
            nums[i++] = 0;
    }
};
