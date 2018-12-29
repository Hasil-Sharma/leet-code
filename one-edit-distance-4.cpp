// https://leetcode.com/problems/one-edit-distance/description/

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.length(), m = t.length(), i = 0, j = 0, diff = 0;
        
        if (m > n) {
            swap(s, t);
            swap(m, n);
        }
        
        while(i < n && j < m){
            if (s[i] == t[j]) {
                i++;
                j++;
            } else if (m == n){
                i++;
                j++;
                diff++;
            } else {
                i++;
                diff++;
            }
        }
        
        diff += n - i;
        
        return diff == 1;
    }
};
