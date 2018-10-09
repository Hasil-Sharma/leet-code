// https://leetcode.com/problems/trapping-rain-water/description/

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, l = 0, r = height.size() - 1, left = 0, right = 0;
        while(r > l){
            if (height[r] > height[l]){
                left = max(left, height[l]);
                res += left - height[l++];
            } else {
                right = max(right, height[r]);
                res += right - height[r--];
            }
        }
        return res;
    }
};
