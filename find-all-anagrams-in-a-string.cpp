// https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> pHash, sHash;
        vector<int> ans;
        
        if (s.length() == 0 || p.length() == 0 || s.length() < p.length()) 
            return ans;
        int sIdx, eIdx = p.length();
        
        for(char &c : p)
            pHash[c]++;
        
        for(int i = 0; i < eIdx; i++)
            sHash[s[i]]++;
        
        sIdx = 0;
        while(true){
            // printHash(sHash);
            if (pHash == sHash) 
                ans.push_back(sIdx);
            if (--sHash[s[sIdx++]] == 0) 
                sHash.erase(s[sIdx - 1]);
            if (eIdx == s.length())
                break;
            sHash[s[eIdx++]]++;
        }        
        return ans;
    }
};
