//https://leetcode.com/problems/search-insert-position/description/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0, j = nums.size(), mid, answer = -1;
        
        while(i < j && answer < 0) {
            mid = (i + j)/2;
            if (nums[mid] == target)
                answer = mid;
            else if (nums[mid] > target) {
                j = mid;
            } else
                i = mid + 1;
        }
        
        return answer >= 0 ? answer : i;
    }
};
