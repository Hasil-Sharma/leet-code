// https://leetcode.com/problems/hamming-distance/description/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x^y, ans = 0;
        while(z){
            ans++;
            z = (z & (z - 1));
        }
        return ans;
    }
};
