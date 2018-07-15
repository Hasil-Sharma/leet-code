// https://leetcode.com/problems/climbing-stairs/description/

class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 2, c;
        if (n < 3) return n;
        // a -> i - 1th, b -> ith
        for(int i = 3; i <= n; i++){
            c = b;
            b = b + a;
            a = c;
        }
        
        return b;
    }
};
