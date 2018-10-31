// https://leetcode.com/problems/sqrtx/description/

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return x;
        int s = 1, e = x;
        // finding the right most number that give its square to be less
        // than or equal to x
        while(e - s > 1){
            int m = s + (e - s) / 2;
            if (m <= x / m) s = m;
            else e = m;
        }
        
        return s;
    }
};
