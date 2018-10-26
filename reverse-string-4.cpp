// https://leetcode.com/problems/reverse-string/description/

class Solution {
public:
    string reverseString(string s) {
        int i = 0, n = s.length();
        
        while(i < n - i - 1)
            swap(s[i++], s[n - i - 1]);
            
        return s;
    }
};
