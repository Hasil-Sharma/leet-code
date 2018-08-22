// https://leetcode.com/problems/custom-sort-string/description/

class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> t(26, 0);
        stringstream ss;
        
        for(char c : T)
            t[c - 'a']++;
        
        for(char c : S)
            while(t[c - 'a']-- > 0) ss << string(1, c);
        
        for(int i = 0; i < 26; i++)
            while(t[i]-- > 0) ss << string(1, 'a' + i);
        
        return ss.str();
    }
};
