// https://leetcode.com/problems/palindrome-number/description/

class Solution {
public:
    bool isPalindrome(int x) {
        int y = 0, temp = abs(x);
        while(temp){
            y = y * 10 + (temp % 10);
            temp = temp / 10;
        }
        return y == x;
    }
};
