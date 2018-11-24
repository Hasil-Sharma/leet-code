// https://leetcode.com/problems/reverse-bits/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int count = 0;
        while(n){
            count++;
            ans = ((ans << 1) | (n & 1));
            n = (n >> 1);
        }
        
        return (ans << (32 - count));
    }
};
