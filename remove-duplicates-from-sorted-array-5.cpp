// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;
        
        while(j < nums.size()){
            swap(nums[i++], nums[j++]);
            while(j < nums.size() && nums[i - 1] >= nums[j])
                j++;
        }
        
        return i;
    }
};
