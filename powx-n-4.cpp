// https://leetcode.com/problems/powx-n/description/

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        
        long nn = (n < 0 ? -1 : 1) * (long)n;
        double ans = 1.0;
        
        while(nn > 0){
            if (nn&1)
                ans = ans * x;
            nn >>= 1;
            x = x*x;
        }
        
        return n < 0 ? 1/ans: ans;
    }
};
