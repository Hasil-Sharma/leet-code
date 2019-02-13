// https://leetcode.com/problems/roman-to-integer/description/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500},
            {'M', 1000}
        };
        
        int prev = 0, ans = 0;
        
        for(char c: s){
            ans = ans + mp[c] + (mp[c] > prev ? -2*prev : 0);
            prev = mp[c];
        }
        
        return ans;
    }
};
