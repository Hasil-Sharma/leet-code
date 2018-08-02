// https://leetcode.com/problems/excel-sheet-column-title/description/

class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        int j;
        while(n){
            j = (n - 1) % 26;
            n = (n - 1) / 26;
            ans.insert(0, 1, 'A' + j);
        }
        return ans;
    }
};
