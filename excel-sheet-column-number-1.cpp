// https://leetcode.com/problems/excel-sheet-column-number/

class Solution {
public:
    int titleToNumber(string s) {
        int radix = 1, ans = 0;
        
        for(int i = s.length() - 1; i >= 0; i--){
            ans += radix*(s[i] - 'A' + 1);
            radix = radix * 26;
        }
        
        return ans;
    }
};
