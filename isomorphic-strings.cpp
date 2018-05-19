// https://leetcode.com/problems/isomorphic-strings/description/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // s and t have the same length
        unordered_map<char, char> hashMap1, hashMap2;
        // hashMap1 key -> value
        // hashMap2 value -> key;
        for(int i = 0; i < s.length(); i++){
            
            auto itr =  hashMap1.find(s[i]);
            if (itr != hashMap1.end() && itr->second != t[i]){
                return false;
            }
            
                        
            itr =  hashMap2.find(t[i]);
            if (itr != hashMap2.end() && itr->second != s[i]){
                return false;
            }
            
            hashMap1[s[i]] = t[i];
            hashMap2[t[i]] = s[i];
            
        }
        
        
        return true;
    }
};
