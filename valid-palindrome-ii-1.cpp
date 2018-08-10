// https://leetcode.com/problems/valid-palindrome-ii/description/

class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while(i < j){
            if (s[i] == s[j]){ i++; j--;}
            else if (helper(s, i + 1, j) || helper(s, i, j - 1))
                return true;
            else return false;
        }
        return true;
    }
    
    bool helper(string& s, int i, int j){
        while(i < j){
            if (s[i] == s[j]) { i++; j--;}
            else return false;
        }
        return true;
    }
};
