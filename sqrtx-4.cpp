// https://leetcode.com/problems/sqrtx/description/

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        int s = 0, e = x;
        
        while(e - s > 1){
            int m = s + (e - s)/2;
            if(m <= x / m) s = m;
            else e = m;
        }
        
        return s;
    }
};
