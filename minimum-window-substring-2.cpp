// https://leetcode.com/problems/minimum-window-substring/description/

class Solution {
public:
    string minWindow(string s, string t) {
        int count = 0, start = 0, st = 0, m = s.length(), n = t.length(), len = INT_MAX;
        unordered_map<char, int> tt, ss;
        
        // collecting all the character counts
        for(char c : t)
            tt[c]++;
        
        for(int end = 0; end < m; end++){
            char c = s[end];
            if (!tt.count(c)) continue;
            if (++ss[c] <= tt[c]) count++; // incrementing count only char contributes to bringing count close to required
            
            if (count == n){
                
                // if s[start] is not part of t or if count of s[start] is more than required
                while(!tt.count(s[start]) || (ss[s[start]] > tt[s[start]])){
                    if (tt.count(s[start]) && ss[s[start]] > tt[s[start]]) --ss[s[start]];
                    start++;
                }
                
                if (end - start + 1 < len){
                    len = end - start + 1;
                    st = start;
                }
            }
            
        }
        
        if (len == INT_MAX) len = 0;
        return s.substr(st, len);
    }
};
