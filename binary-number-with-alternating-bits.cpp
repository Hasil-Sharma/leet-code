// https://leetcode.com/problems/binary-number-with-alternating-bits/description/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int temp = (n ^ (n >> 1)) + 1;
        return !(temp & (temp - 1));
    }
};
