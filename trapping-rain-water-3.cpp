// https://leetcode.com/problems/trapping-rain-water/description/

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, lmax = 0, rmax = 0, lidx = 0, ridx = height.size() - 1;
        
        while(lidx < ridx){
            if (height[lidx] > height[ridx]){
                rmax = max(rmax, height[ridx]);
                ans += rmax - height[ridx--];
            } else {
                lmax = max(lmax, height[lidx]);
                ans += lmax - height[lidx++];
            }
        }
        
        return ans;
    }
};
