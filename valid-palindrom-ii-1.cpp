// https://www.lintcode.com/problem/valid-palindrome-ii/description

class Solution {
public:
    /**
     * @param s: a string
     * @return: nothing
     */
    bool validPalindrome(string &s) {
        // Write your code here
        int i = 0, j = s.length() - 1;
        
        while(j > i){
            if (s[i++] == s[j--]) continue;
            else return check(s, i, j - 1) || check(s, i + 1, j);
        }
        return true;
    }
    
    bool check(string&s, int i, int j){
        while(j > i){
            if (s[i++] == s[j--]) continue;
            else return false;
        }
        return true;
    }
};
