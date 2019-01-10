// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen_chars;
        int ans = 0, n = s.length(), st = 0, en = 0;
        
        while(en < n){
            while(seen_chars.count(s[en]) && s[st] != s[en]){
                seen_chars.erase(s[st]);
                ++st;
            }
            
            if (seen_chars.count(s[en]))
                ++st;
            
            seen_chars.insert(s[en]);
            ++en;
            
            ans = max(ans, en - st);
        }
        
        return ans;
    }
};
