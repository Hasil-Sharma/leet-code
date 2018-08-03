// https://leetcode.com/problems/roman-to-integer/description/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mapping({{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}});
        int c = 0, ans = 0;
        if (s.length() == 0) return ans;
        while(c < s.length() - 1){
            if (mapping[s[c]] < mapping[s[c+1]]) ans -= mapping[s[c]];
            else ans += mapping[s[c]];
            ++c;
        }
        ans += mapping[s[c]];
        return ans;
    }
};
