// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/

class Solution {
public:
    int findMin(vector<int>& nums, int start = 0, int end = -2) {
        end = (end == -2) ? nums.size() - 1 : end;
        int ans = INT_MAX;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if (nums[start] < nums[mid]) 
                return min(nums[start], findMin(nums, mid + 1, end));
            else if (nums[start] < nums[end] && nums[end] < nums[mid])
               return  nums[start];
            else 
                return min(nums[mid], min(findMin(nums, mid + 1, end), findMin(nums, start, mid - 1)));
        }
        
        return ans;
    }
};
