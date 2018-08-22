// https://leetcode.com/problems/divide-two-integers/description/

class Solution {
public:
    int divide(int dividend, int divisor) {
        int ans = 0, temp;
        bool neg = (dividend < 0) ^ (divisor < 0);
        long int div = labs(dividend), dis = labs(divisor);
        
        if (dividend == INT_MIN && dis == 1){
            return neg ? INT_MIN : INT_MAX;
        }
        
        while(div >= dis){
            temp = helper(div, dis);
            div = div - temp * dis;
            ans += temp;
        }
        
        return neg ? -ans : ans;
    }
    
    int helper(long div, long dis){
        int i = 0;
        while(div >= dis){
            i++;
            dis = (dis << 1);
        }
        return 1 << (i - 1);
    }
};
