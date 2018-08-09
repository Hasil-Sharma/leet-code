// https://leetcode.com/problems/move-zeroes/description/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        while(j < nums.size()){
            if (!nums[j] && !nums[i]) j++;
            else if (nums[j]){
                swap(nums[i], nums[j]);
                i++; j++;
            }
        }
    }
};
