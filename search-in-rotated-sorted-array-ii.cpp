// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

class Solution {
public:
    bool search(vector<int>& nums, int target, int low = 0, int high = -2) {
        high = (high == - 2) ? nums.size() - 1 : high;
        while(low <= high){
            int mid = low + (high - low) / 2;            
            if (target == nums[mid]) return true;
            else if (target < nums[mid] && nums[low] < target ) 
                return search(nums, target, low, mid - 1);
            else if (nums[mid] < target && nums[high] > target) 
                return search(nums, target, mid + 1, high);
            else 
                return search(nums, target, mid + 1, high) || search(nums, target, low, mid - 1);
        }
        return false;
    }
};
