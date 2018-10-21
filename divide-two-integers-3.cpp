// https://leetcode.com/problems/divide-two-integers/description/

class Solution {
public:
    int divide(int dividend, int divisor) {
        long  div = labs(dividend), dis = labs(divisor), ans = 0;
        
        while(div >= dis){
            long m = 1;
            long num = dis;
            
            while((num << 1) < div){
                num <<= 1;
                m <<= 1;
            }
            ans += m;
            div = div - num;
        }
        
        if ((dividend < 0) ^ (divisor < 0)) return -ans < INT_MIN ? INT_MIN : -ans;
        return ans > INT_MAX ? INT_MAX : ans;
    }
};
