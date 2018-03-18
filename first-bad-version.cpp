//https://leetcode.com/problems/first-bad-version/description/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1, end = n;
        int mid;
        bool midFlag, startFlag, endFlag;
        if (isBadVersion(start)) return start;
        
        while(true){
            mid = start + (end - start) / 2;
            midFlag = isBadVersion(mid); startFlag = isBadVersion(start); endFlag = isBadVersion(end);
            
            // Reducing problem to either a three or two problems
            // In case of two elements mid is same start start
            // In case of three elements if first element is true than all the rest should be true as well
            // Such a case never happens
            if (end - start + 1 == 3 || end - start + 1 == 2){
                return (midFlag) ? mid : end;
            }
            
            if (midFlag) end = mid;
            else start = mid;
        }
    }
};
