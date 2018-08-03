//https://www.lintcode.com/problem/one-edit-distance/description

class Solution {
public:
    /**
     * @param s: a string
     * @param t: a string
     * @return: true if they are both one edit distance apart or false
     */
    bool isOneEditDistance(string &s, string &t) {
        // write your code here
        int count = 0, m = s.length(), n = t.length(), i = 0;
        if (m < n) {
            swap(m, n);
            swap(t, s);
        }
        if (m - n > 1) 
            return false;
            
        if (m == n){
            for(int i = 0; i < m; i++){
                if (s[i] != t[i]){
                    if (count < 1) 
                        ++count;
                    else 
                        return false;
                }
            }
        } else {
            int i = 0, j = 0;
            while(i < m){
                if (s[i] == t[j]){
                    i++; j++;
                } else if (count < 1) {
                    i++; ++count;
                } else 
                    return false;
            }
        }
        return count == 1;
    }
};
