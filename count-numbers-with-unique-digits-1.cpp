// https://leetcode.com/problems/count-numbers-with-unique-digits/description/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0 || n == 1) return n ? 10 : 1;
        int curr = 9, ans = 10, temp = 9;
        
        for(int i = 2; i <= n && i < 10; i++){
            curr *= temp;
            ans += curr;
            temp--;
        }
        
        return ans;
    }
};
