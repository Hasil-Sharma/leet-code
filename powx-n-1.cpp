// https://leetcode.com/problems/powx-n/description/

class Solution {
public:
    double myPow(double x, int n) {
        double temp;
        if (n == 0) temp = 1.0;
        else if (n == 1) temp = x;
        else if (n == -1) temp = 1.0 / x;
        else {
            temp = myPow(x, n / 2);
            temp = (n & 1 ? myPow(x, n % 2) : 1.0 ) * temp * temp;
        }
        return temp;
    }
};
