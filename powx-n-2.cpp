// https://leetcode.com/problems/powx-n/description/

class Solution {
public:
    double myPow(double x, int n) {
        bool minus = false, max_min = false;
        double ans;
        if (n == 0) return 1;
        
        if (n < 0) {
            minus = true;
            max_min = n == INT_MIN;
            n = n != INT_MIN ? -1 * n : INT_MAX;
        }
        
        if ( n % 2 == 0){
            double temp = myPow(x, n / 2);
            ans = temp * temp;
        } else {
            double temp = myPow(x, n / 2);
            ans = x * temp * temp;
        }
        
        if (minus){
            if (max_min)
                ans = ans * x;
            ans = 1.0 / ans;
        }
        return ans;
    }
};
