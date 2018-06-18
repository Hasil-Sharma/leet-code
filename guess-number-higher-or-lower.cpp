// https://leetcode.com/problems/guess-number-higher-or-lower/description/

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long low = 1, high = n, mid;
        
        while(low <= high){
            mid = low + ((high - low) >> 1);
            int g = guess(mid);
            if (g == 0) return mid;
            else if (g == 1) low = mid + 1;
            else high = mid - 1;
        }
    }
};
