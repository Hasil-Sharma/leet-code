// https://leetcode.com/problems/find-pivot-index/description/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rt = 0, lt = 0, ans = -1;
        
        for(auto num : nums)
            rt += num;
        
        for(int i = 0; i < nums.size(); i++){
            rt = rt - nums[i];
            if (rt == lt) return i;
            lt += nums[i];
        }
        
        return -1;
        
    }
};
