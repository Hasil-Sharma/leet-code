// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 1, n = s.length(), ans = n > 0;
        if (n == 0) return ans;
        
        unordered_map<char, int> hashMap;
        
        hashMap[s[i]]++;
        
        while(j < n){
            char idx = s[j];
            while(hashMap[idx] != 0)
                hashMap[s[i++]]--;
            ans = max(ans, j - i + 1);
            hashMap[idx]++;
            j++;
        }
        
        return ans;
    }
};
