// https://www.lintcode.com/problem/palindromic-substrings/description

class Solution {
public:
    /**
     * @param str: s string
     * @return: return an integer, denote the number of the palindromic substrings
     */
    int countPalindromicSubstrings(string &str) {
        // write your code here
        int ans = 0;
        for(int i = 0; i < str.length(); i++){
            ans += check(str, i, i);
            ans += check(str, i, i + 1);
        }
        
        return ans;
    }
    
    int check(string& str, int left, int right){
        int count = 0;
        
        while(left >= 0 && right < str.length() && str[left--] == str[right++])
        ++count;
        
        return count;
    }
};
