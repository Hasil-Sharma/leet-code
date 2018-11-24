// https://leetcode.com/problems/sqrtx/description/

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        int a = 0, b = x, m;
        // right most m such that m * m <= x
        
        while(b - a > 1){
            m = a + (b - a) / 2;
            if (m > x/m) b = m;
            else a = m;
        }
        
        return a;
    }
};
