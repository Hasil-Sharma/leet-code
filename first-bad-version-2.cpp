// https://leetcode.com/problems/first-bad-version/description/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
    // right most good
        int l = isBadVersion(1) ? 0 : 1, r = n;
        while(r - l > 1){
            int m = l + (r - l) / 2;
            if (isBadVersion(m)) r = m;
            else l = m;
        }
        return l + 1;
    }
};
