// https://leetcode.com/problems/climbing-stairs/description/

class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) return n;
        int a = 1, b = 1; 
        // a: number of steps to reach n - 1
        // b: number of steps to reach n - 2
        
        for(int i = 2; i <= n; i++){
            a = b + a;
            b = a - b;
        }
        
        return a;
    }
};
