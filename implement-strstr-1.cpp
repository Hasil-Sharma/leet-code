// https://www.lintcode.com/problem/implement-strstr/description

class Solution {
public:
    /*
     * @param source: source string to be scanned.
     * @param target: target string containing the sequence of characters to match
     * @return: a index to the first occurrence of target in source, or -1  if target is not part of source.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        int m = source ? strlen(source) : -1, n = target ? strlen(target) : -1;
        if (n == 0 && m >= n) return 0;
        else if (m == -1 || n == -1) return -1;
        for(int i = 0; i < m; i++){
            if (source[i] == target[0] && check(source, target, i, m, n))
                return i;
        }
        return -1;
    }
    
    bool check(const char *s, const char *t, int start, int m, int n){
        if (m - start < n) return false;
        
        for(int i = 0; i < n; i++)
            if (t[i] != s[start++]) 
                return false;
        
        return true;
    }
};
