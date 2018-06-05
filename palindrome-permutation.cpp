// https://www.lintcode.com/problem/palindrome-permutation/description

class Solution {
public:
    /**
     * @param s: the given string
     * @return: if a permutation of the string could form a palindrome
     */
    bool canPermutePalindrome(string &s) {
        // write your code here
        bool ans = true;
        unordered_map<char, int> charCount;
        int count = 0;
        
        for(char &c : s) {
            count += (++charCount[c] % 2 ? 1 : -1);
        }
            
        return count <= 1;
    }
};
