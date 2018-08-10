// https://leetcode.com/problems/roman-to-integer/description/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> char2Int = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int ans = 0, prev = 0;
        
        for(char c : s){
            ans += char2Int[c];
            if (char2Int[c] > prev) ans -= 2*prev;
            prev = char2Int[c];
        }
        return ans;
    }
};
