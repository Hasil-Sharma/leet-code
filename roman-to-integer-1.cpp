// https://leetcode.com/problems/roman-to-integer/description/

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0, prev = 0, cur = 0;
        unordered_map<char, int> hashMap(
            {{'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}}
        );
            
        for(char& c : s){
            cur = hashMap[c];
            ans += cur - (cur <= prev ? 0 : prev << 1);
            prev = cur;
        }
        
        return ans;
    }
};
