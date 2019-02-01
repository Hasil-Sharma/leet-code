// https://leetcode.com/problems/palindrome-number/description/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        int y = 0, orig = x;
        
        while(orig){
            y = y*10 + (orig%10);
            orig /= 10;
        }
        
        return x == y;
    }
};
