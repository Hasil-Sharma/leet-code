// https://www.lintcode.com/problem/valid-palindrome/description

class Solution {
public:
    /**
     * @param s: A string
     * @return: Whether the string is a valid palindrome
     */
    bool isPalindrome(string &s) {
        // write your code here
        int i = 0, j = s.length() - 1;
        while(j > i){
            if (isalnum(s[i]) && isalnum(s[j])){
                if (s[i] == s[j] || tolower(s[i]) == tolower(s[j])){
                    i++; j--;
                } else return false;
            } else if (isalnum(s[i])) j--;
            else if (isalnum(s[j])) i++;
            else {
                j--; i++;
            }
        }
        
        return true;
    }
};
