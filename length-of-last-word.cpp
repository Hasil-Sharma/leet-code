// https://leetcode.com/problems/length-of-last-word/description/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int endWidx = s.length() - 1, startWidx;
        
        // iterating till the last character of last word is encountered
        for(; endWidx >= 0 && s[endWidx] == ' '; endWidx--);
        
        startWidx = endWidx;
        // iterating till the first character of the last word
        for(; startWidx >= 0 && s[startWidx] != ' '; startWidx--);
        
        return endWidx - startWidx;
        
    }
};
