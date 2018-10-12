// https://leetcode.com/problems/sort-colors/description/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        // 0 to low - 1 all 0
        // low to mid - 1 all 1
        // mid to high - 1 - still figuring
        // high to n - 1 all 2
        while(mid <= high){
            if (nums[mid] == 0) swap(nums[mid++], nums[low++]);
            else if (nums[mid] == 1) mid++;
            else swap(nums[mid], nums[high--]);
        }
    }
};
