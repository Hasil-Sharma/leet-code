// https://leetcode.com/problems/roman-to-integer/description/

class Solution {
public:
    int romanToInt(string s) {
        int prev = 0, ans = 0;
        unordered_map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100},
                                       {'D', 500}, {'M', 1000}};
        for(char c : s){
            ans += mp[c];
            if (prev < mp[c]) ans -= 2*prev;
            prev = mp[c];
        }
        
        return ans;
    }
};
