// https://leetcode.com/problems/reverse-string/description/

class Solution {
public:
    string reverseString(string s) {
        if (s.length())
        reverseHelper(s, 0);
        return s;
    }
    
    void reverseHelper(string& s, int i){
        if (s.length() - 1 - i > i){
            swap(s[i], s[s.length() - 1 - i]);
            reverseHelper(s, i+1);
        }
    }
};
