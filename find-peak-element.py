// https://leetcode.com/problems/find-peak-element/description/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0, end = nums.size(), mid, ans = -1;
        if (end == 1) return start;
        while(start < end && ans < 0){
            mid = (start + end) / 2;
            if(mid - 1 >= 0 && mid + 1 < nums.size()){
                if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) ans = mid;
                else if (nums[mid - 1] > nums[mid]) end = mid;
                else if (nums[mid + 1] > nums[mid]) start = mid;
            } else if (mid - 1 >= 0) {
                // mid is the last element
                ans = (nums[mid] > nums[mid - 1]) ? mid : mid - 1;
            } else {
                // mid is the first element
                ans = (nums[mid] > nums[mid + 1]) ? mid : mid + 1;
            }
        }
        return ans;
    }
};
