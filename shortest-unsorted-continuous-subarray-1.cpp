// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/submissions/1
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, num_min = INT_MAX, num_max = INT_MIN;
        
        // finding the l and r where nums[l] != sorted_nums[l] && nums[r] != sorted_nums[r]
        while(l < r && nums[l] <= nums[l + 1]) l++;
        // case when entire array is properly sorted
        if (l >= r) return 0;
        while(r >= 0 && nums[r - 1] <= nums[r]) r--;
        
        // finding min and max in range [l, r]
        // all the numbers from [0, l - 1] should be less than min 
        // all the number from [r + 1, n - 1] should be greater than max
        
        for(int i = l; i <= r; i++){
            num_min = min(num_min, nums[i]);
            num_max = max(num_max, nums[i]);
        }
        
        
        while(l >= 0 && num_min < nums[l]) l--;
        while(r < nums.size() && num_max > nums[r]) r++;
        return r - l - 1;
        
    }
};
