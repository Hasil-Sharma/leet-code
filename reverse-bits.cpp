// https://leetcode.com/problems/reverse-bits/description/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        
        for(int i = 0; i < 32; i++){
            result = result << 1; // making space for new bit
            result = result | (n & 1); // taking the last bit of n and adding it to result
            n = n >> 1; // removing last one bit from n
        }
        return result;
    }
};
