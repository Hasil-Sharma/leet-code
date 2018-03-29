// https://leetcode.com/problems/reverse-words-in-a-string-iii/description/

class Solution {
public:
    
    void helper(string& s, int startIdx, int len){
        int endIdx = startIdx + len - 1;
        while(startIdx <= endIdx){
            swap(s[startIdx++], s[endIdx--]);
        }
    }
    string reverseWords(string s) {
        int startIdx = 0, len = 0;
        for(char c : s){
            len += 1;
            if (c == ' ') {
                helper(s, startIdx, len - 1);
                startIdx += len;
                len = 0;
            }
        }
        
        helper(s, startIdx, len);
        return s;
    }
};
