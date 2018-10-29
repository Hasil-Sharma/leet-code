// https://leetcode.com/problems/reverse-integer/description/

class Solution {
public:
    int reverse(int x) {
        long ans = 0, sign = x < 0;
        x = sign ? -x : x;
        
        while(x && x != INT_MIN){
            ans = ans*10 + (x % 10);
            if (ans > INT_MAX) return 0;
            x /= 10;
        }
        
        return sign ? -ans : ans;
    }
};
