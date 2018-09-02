// https://leetcode.com/problems/divide-two-integers/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && abs(divisor) == 1) return divisor == -1 ? INT_MAX : INT_MIN;
        int ans = 0, sign = (dividend < 0 ^ divisor < 0) ? -1 : 1;
        long dvd = labs(dividend), dvs = labs(divisor);
        
        while(dvd >= dvs){
            int temp = helper(dvd, dvs);
            dvd = dvd - dvs*temp;
            ans += temp;   
        }
        
        return sign*ans;
    }
    
    int helper(long dvd, long dvs){
        long i = 1;
        while(dvd >= dvs*i)
            i = i * 2;
        return i / 2;
    }
};
