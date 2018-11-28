// https://leetcode.com/problems/trapping-rain-water/submissions/

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, l = 0, r = 0, i = 0, j = height.size() - 1;
        
        while(i < j){
            if (height[i] < height[j]){
                l = max(l, height[i]);
                ans += l - height[i++];
            } else {
                r = max(r, height[j]);
                ans += r - height[j--];
            }
        }
        
        return ans;
    }
};
