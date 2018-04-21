// https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int ans = -1;
        int max_so_far = 0;
        
        for(int i = 0; i < nums.size(); i++){
            
            // case when current number is greater than twice of number max so far
            if (nums[i] >= 2 * max_so_far) {
                max_so_far = nums[i];
                if (!(ans != -1 && nums[i] == 2 * max_so_far))
                    ans = i;
            } else if (nums[i] > max_so_far){
                max_so_far = nums[i];
                ans = -1;
            } else if (nums[i] * 2 > max_so_far){
                ans = -1;
            }
        }
        
        return (nums.size() > 1) ? ans : 0;
    }
};
