// https://leetcode.com/problems/word-pattern/description/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;
        stringstream ss(str);
        string token;
        int i = 0;
        
        while( ss >> token){
            if (i == pattern.size()) return false;
            if (mp1.count(pattern[i]) && mp1[pattern[i]] != token) return false;
            if (mp2.count(token) && mp2[token] != pattern[i]) return false;
            mp1[pattern[i]] = token;
            mp2[token] = pattern[i++];
        }
        
        return i == pattern.size();
    }
};
