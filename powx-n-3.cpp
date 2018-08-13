// https://leetcode.com/problems/powx-n/description/

class Solution {
public:
    double myPow(double x, int n) {
        long nl = n;
        double ans = 1.0;
        if (nl < 0){
            x = 1.0 / x;
            nl = -1l * n;
        }
        
        while(nl){
            if (nl & 1){
                ans = ans * x;
                nl = nl - 1;
            }
            nl /= 2;
            x = (x * x);
        }
        return ans;
    }
    
 
};
