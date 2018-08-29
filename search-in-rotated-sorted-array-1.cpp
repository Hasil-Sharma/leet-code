// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution {
public:
    
    int findPivot(vector<int>& nums){
        int low = 0, high = nums.size() - 1, m;
        
        while(low <= high){
            if (low == high) 
                return low;
            m = low + (high - low) / 2;
            if (m > low && nums[m-1] > nums[m])
                return m - 1;
            else if (m < high && nums[m] > nums[m + 1])
                return m;
            else if (nums[low] >= nums[m]) high = m - 1;
            else low = m + 1;
        }
        return -1;
    }
    
    int bs(vector<int>& nums, int low, int high, int target){
        int m;
        while(low < high){
            m = low + (high - low) / 2;
            if (nums[m] == target) return m;
            else if (nums[m] > target) high = m - 1;
            else low = m + 1;
        }
        
        return low == high && nums[low] == target ? low : -1;
    }
    int search(vector<int>& nums, int target) {
        int p = findPivot(nums);
        int n = nums.size();
        if (p == -1) return bs(nums, 0, n - 1, target);
        else if (n > 0 && nums[0] <= target && target <= nums[p]) return bs(nums, 0, p, target);
        else return bs(nums, p + 1, n - 1, target);
    }
};
