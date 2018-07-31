// https://www.lintcode.com/problem/sqrtx/description

class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        if (x == 0 || x == 1) return x;
        int s = 1, e = x, ans;
        
        
        while(e >= s){
            int mid = s + (e - s) / 2;
            if (mid > x / mid){
                e = mid - 1;
            } else {
                ans = mid;
                s = mid + 1;
            }
        }
        
        return ans;
    }
};
