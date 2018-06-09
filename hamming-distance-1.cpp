// https://leetcode.com/problems/hamming-distance/description/

class Solution {
public:
    int hammingDistance(int x, int y) {
        x ^= y;
        int ans = 0;
        while(x){
            ans += (x&1);
            x = x >> 1;
        }
        return ans;
    }
};
