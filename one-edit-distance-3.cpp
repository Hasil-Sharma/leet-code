// https://leetcode.com/problems/one-edit-distance/description/

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.length(), n = t.length();
        if (n > m){
            swap(s, t);
            swap(m, n);
        }
        // s is longer than t
        for(int i = 0; i < m; i++){
            if (i < n && s[i] != t[i])
                return m == n ? check(s, t, i + 1, i + 1) : check(s, t, i + 1, i);
        }
        return m - n == 1;
    }
    
    bool check(string& s, string& t, int i, int j){
        while(i < s.length() && j < t.length())
            if (s[i++] != t[j++]) return false;
        return i == s.length() && j == t.length();
    }
};
