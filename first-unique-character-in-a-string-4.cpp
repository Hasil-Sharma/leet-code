// https://leetcode.com/problems/first-unique-character-in-a-string/description/

class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length(), ans = n + 1;
        vector<int> hash(26, n + 1);
        
        for(int i = 0; i < n; i++){
            int idx = s[i] - 'a';
            if (hash[idx] < n) hash[idx] = n;
            else if (hash[idx] == n + 1) hash[idx] = i;
        }
        
        for(int i = 0; i < 26; i++)
            ans = min(hash[i], ans);
        
        return ans < n ? ans : -1;
    }
};
