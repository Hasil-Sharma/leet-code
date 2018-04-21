// https://leetcode.com/problems/largest-number-at-least-twice-of-others/submissions/1

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, index;
        // max2 < max1;
        for(int i = 0; i < nums.size(); i++){
            if (max1 < nums[i]){
                max2 = max1;
                max1 = nums[i];
                index = i;
            } else if (max2 < nums[i]){
                max2 = nums[i];
            }
        }
        return (max1 >= 2 * max2) ? index : -1;
    }
};
