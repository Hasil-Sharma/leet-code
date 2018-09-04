// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int p = findPivot(nums);
        if (p == -1) return bs(nums, target, 0, nums.size() - 1);
        else if (nums[0] <= target && target <= nums[p]) return bs(nums, target, 0, p);
        else return bs(nums, target, p + 1, nums.size() - 1);
    }
    
    int findPivot(vector<int>& nums){
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int m = l + (r - l) / 2;
            if (m < r && nums[m] > nums[m + 1]) return m;
            else if (m > l && nums[m] < nums[m - 1]) return m - 1;
            else if (nums[l] >= nums[m]) r = m - 1;
            else l = m + 1;
        }
        return -1;
    }
    
    int bs(vector<int>& nums, int target, int l, int r){
        while(l < r){
            int m = l + (r - l) / 2;
            if (nums[m] == target) return m;
            else if (nums[m] > target) r = m -1;
            else l = m + 1;
        }
        return l == r && nums[l] == target ? l : -1;
    }
};
