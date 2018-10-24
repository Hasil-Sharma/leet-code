// https://leetcode.com/problems/word-pattern/description/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> m1;
        unordered_map<string, int> m2;
        stringstream ss(str);
        int i = 0, n = pattern.length();
        
        for(string temp; ss >> temp; i++){
            if (i == n || m1[pattern[i]] != m2[temp])
                return false;
            m1[pattern[i]] = m2[temp] = i + 1;
        }
        
        return i == n;
    }
};
