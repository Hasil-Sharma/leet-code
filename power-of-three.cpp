// https://leetcode.com/problems/power-of-three/description/

class Solution {
public:
    bool isPowerOfThree(int n) {
        // Write your code here
        int maxThree = 1162261467;
        return n > 0 && (maxThree % n == 0);
    }
};
