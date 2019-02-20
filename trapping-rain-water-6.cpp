// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, n = height.size(), i = 0, j = n - 1, lm = 0, rm = 0;
        
        while(i < j){
            if (height[i] > height[j]){
                height[j] >= rm ? (rm = height[j]) : ans += (rm - height[j]);
                j--;
            } else {
                height[i] >= lm ? (lm = height[i]) : ans += (lm - height[i]);
                i++;
            }
        }
        
        return ans;
    }
};
