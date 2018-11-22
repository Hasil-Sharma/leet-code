// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, len = 1;
        
        for(int i = 0; i < s.length(); i++){
            helper(s, i, i + 1, start, len);
            helper(s, i - 1, i + 1, start, len);
        }
        
        return s.substr(start, len);
    }
    
    
    void helper(string& s, int low, int high, int& start, int& len){
        int n = s.length();
        
        while(low >= 0 && high < n){
            if (s[low] == s[high]){
                if (high - low + 1 > len){
                    start = low;
                    len = high - low + 1;
                }
                
            } else break;
            low--;
            high++;
        }
    }
};
