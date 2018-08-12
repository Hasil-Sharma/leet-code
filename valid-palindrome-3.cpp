// https://leetcode.com/problems/valid-palindrome/description/

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1, n = s.length();
        while(j > i){
            while(!isalnum(s[i]) && i < n) i++;
            while(!isalnum(s[j]) && j >= 0) j--;
            if (i < j && tolower(s[i]) == tolower(s[j])) {i++; j--;}
            else if (i < j) return false;
        }
        return true;
    }
};
