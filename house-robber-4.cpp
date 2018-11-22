// https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0, b = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if (i % 2) b = max(a, b + nums[i]);
            else a = max(a + nums[i], b);
        }
        
        return max(a, b);
    }
};
