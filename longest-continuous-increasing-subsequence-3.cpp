// https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() < 1) return 0;
        int prev = nums[0] - 1, count = 0, temp = 0;
        for(int num : nums){
            if (num > prev){
                temp++;
            } else {
                count = max(count, temp);
                temp = 1;
            }
             prev = num;
        }
        count = max(count, temp);
        return count;
    }
};
