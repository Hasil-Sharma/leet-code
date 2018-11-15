// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), start = 0, len = 1;
        
       for(int i = 1; i < n; i++){
           helper(i-1, i, n, start, len, s);
           helper(i-1, i+1, n, start, len, s);
       }
    
        return s.substr(start, len);
    }
    
    void helper(int l, int h, int n, int& start, int& len, string& s){
        while(l >= 0 && h < n && s[l] == s[h]){
            if (h - l + 1 > len){
                start = l;
                len = h - l + 1;
            }
            
            h++;
            l--;
        }
    }
};
