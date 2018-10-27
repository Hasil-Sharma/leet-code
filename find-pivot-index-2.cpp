// https://leetcode.com/problems/find-pivot-index/description/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0, lt = 0, ans = -1;
        
        for(auto num : nums)
            total += num;
        
        for(int i = 0; i < nums.size(); i++){
            if (lt == total - nums[i] - lt) return i;
            lt += nums[i];
        }
        
        return -1;
        
    }
};
