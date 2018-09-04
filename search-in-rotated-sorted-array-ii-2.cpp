// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        
        while(l < r){
            int m = l + (r - l)/2;
            if (nums[m] == target || nums[l] == target || nums[r] == target)
                return true;
            else if (nums[l] == nums[r]){l++; r--;}
            else if (nums[l] <= nums[m]){
                if (nums[l] <= target && target < nums[m]) r = m - 1;
                else l = m + 1;
            } else {
                if (nums[m] < target && target <= nums[r]) l = m + 1;
                else r = m - 1;
            }
        }
        
        return l == r && nums[l] == target;
    }
};
