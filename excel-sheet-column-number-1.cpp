// https://leetcode.com/problems/excel-sheet-column-number/

class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for(int i = 0; i < s.length(); result = result * 26 + s[i++] - 'A' + 1);
        return result;
    }
};
