// https://leetcode.com/problems/first-unique-character-in-a-string/description/

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> char_count(26, 0);
        int ans = 0;
        for(char c : s)
            char_count[c - 'a']++;
        
        for(char c : s){
            if (char_count[c - 'a'] == 1)
                return ans;
            ++ans;
        }
        
        return -1;
    }
};
