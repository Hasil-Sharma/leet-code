// https://www.lintcode.com/problem/one-edit-distance/description

class Solution {
public:
    /**
     * @param s: a string
     * @param t: a string
     * @return: true if they are both one edit distance apart or false
     */
    bool isOneEditDistance(string &s, string &t) {
        // write your code here
        int n = s.length(), m = t.length(), count = 0;
        if (m > n) {
            swap(t, s);
            swap(m, n);
        }
        
        if (n - m > 1) return false;
        
        int i = 0, j = 0;
        while(i < n && j < m){
            if (s[i] == t[j]){
                i++; j++;
            } else if (m == n && tolower(s[i]) == tolower(t[j])){
                count++; i++; j++;
            } else {
                count++; i++;
            }
        }
        while(i < n) {
            count++; i++;
        }
        return count == 1;
    }
};
