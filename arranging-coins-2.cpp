// https://leetcode.com/problems/arranging-coins/description/

class Solution {
public:
    int arrangeCoins(int n) {
        long low = 1, high = n, mid, coin;
        
        while(low <= high){
            mid = low + (high - low) / 2;
            coin = mid * (mid + 1) / 2;
            if (coin < n) low = mid + 1;
            else if (coin > n) high = mid - 1;
            else return mid;
        }
        
        return low - 1;
    }
};
