// https://leetcode.com/problems/excel-sheet-column-title/description/

class Solution {
public:
    string convertToTitle(int n) {
        stringstream ss;
        while(n){
            int c = (n - 1) % 26;
            n = (n - 1) / 26;            
            ss << string(1, 'A' + c);
        }
        string ans = ss.str();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
