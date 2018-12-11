// https://leetcode.com/problems/zigzag-conversion/description/

class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";
        int i = 0, n = s.length(), diff = 2*(numRows - 1), dd = diff;
        if (numRows == 1) return s;
        while(i < numRows){
            // cout << i << ": ";
            for(int j = i; j < n; j += dd){
                ans += string(1, s[j]);
                // cout << j << ",";
                dd = abs(diff - dd) ? abs(diff - dd) : diff;
            }
            i++;
            dd = 2*i;
            // cout << "(" << dd << ")" << endl;
        }
        
        return ans;
    }
};
