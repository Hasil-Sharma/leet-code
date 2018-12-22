// https://leetcode.com/problems/trapping-rain-water/description/

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, i = 0, j = height.size() - 1, maxl = 0;
        while(i < j){
            
            if (height[i] < height[j]){
                maxl = max(height[i], maxl);
                ans += maxl - height[i];
                i++;
            } else {
                maxl = max(height[j], maxl);
                ans += maxl - height[j];
                j--;
            }
        }
        
        return ans;
    }
};
