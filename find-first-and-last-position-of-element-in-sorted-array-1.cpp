// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int m, n = nums.size(), l = 0, r = n;
        vector<int> ans = {-1, -1};
        
        // finding left
        while(l < r){
            m = l + (r - l) / 2;
            nums[m] < target ? l = m + 1 : r = m;
        }
        
        (l < n && nums[l] == target) ? ans[0] = l : -1;
        
        r = n;
        
        // finding right
        while(l < r){
            m = l + (r - l) / 2;
            nums[m] <= target ? l = m + 1 : r = m;
        }
        
        (l > 0 && nums[l-1] == target) ? ans[1] = l - 1 : -1;
        
        return ans;
    }
};
