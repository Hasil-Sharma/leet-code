// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;
        while(s <= e){
            int m = s + (e - s) / 2;
            if (m > s && nums[m] < nums[m-1])
                return nums[m];
            else if (m < e && nums[m] > nums[m+1])
                return nums[m+1];
            else if (nums[s] >= nums[m]) e = m - 1;
            else s = m + 1;
        }
        
        return nums[0];
    }
};
