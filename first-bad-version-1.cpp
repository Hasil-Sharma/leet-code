// https://leetcode.com/problems/first-bad-version/description/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s = 1, e = isBadVersion(1) ? 1 : n, m;
        
        // find leftmost true
        while(e - s > 1){
            m = s + (e - s) / 2;
            if (isBadVersion(m)) e = m;
            else s = m;
        }
        
        return e;
    }
};
