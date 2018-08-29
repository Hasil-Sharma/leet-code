// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution {
public:
    
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1, m;
        if (h < l) return -1;
        
        while(l < h){
            m = l + (h -l)/2;
            if (nums[m] == target) return m;
            // l to m is sorted
            if (nums[l] <= nums[m]){
                if (nums[l] <= target && nums[m] > target) h = m - 1;
                else l = m + 1;
            } else {
            // m to h must be sorted
                if (nums[m] < target && nums[h] >= target) l = m + 1;
                else h = m - 1;
            }
        }
        
        return h == l && nums[h] == target ? h : -1;
    }
};
