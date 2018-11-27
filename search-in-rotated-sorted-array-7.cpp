// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1, m;
        
        while(i <= j){
            m = i + (j - i)/2;
            if (nums[m] == target) return m;
            else if (nums[i] <= nums[m]){
                if (nums[i] <= target && target < nums[m]) j = m - 1;
                else i = m + 1;
            } else {
                if (nums[m] < target && nums[j] >= target) i = m + 1;
                else j = m - 1;
            }
        }
        
        return -1;
    }
};
