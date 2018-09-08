// https://leetcode.com/problems/reverse-string/description/

class Solution {
public:
    string reverseString(string s) {
        int i = 0;
        
        while(s.length() && i < s.length() - 1 - i){
            swap(s[i], s[s.length() - 1 - i]);
            ++i;
        }
        return s;
    }
};
