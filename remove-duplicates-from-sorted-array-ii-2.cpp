// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;
        while(j < nums.size() && i < nums.size()){
            if (i < 2 || nums[i] > nums[i - 2]) i++;
            else  if (nums[i - 2] >= nums[j]) j++;
            else if (nums[j] > nums[i]) swap(nums[j++], nums[i++]);
        }
        return i;
    }
};
