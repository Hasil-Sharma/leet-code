// https://leetcode.com/problems/can-place-flowers/description/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int zeroCount = 1, possibleSpots = 0;
        
        for(int n : flowerbed){
            if (n == 0){
                zeroCount++;
                if (zeroCount == 3){
                    possibleSpots++;
                    zeroCount = 1;
                }
            } else {
                zeroCount = 0;
            }
        }
        if (zeroCount == 2) possibleSpots++;
        return (possibleSpots >= n) ? true : false;
    }
};
