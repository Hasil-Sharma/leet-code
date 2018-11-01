// https://leetcode.com/problems/ransom-note/description/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> rn(26, 0), mag(26, 0);
        str2Vec(ransomNote, rn);
        str2Vec(magazine, mag);
        
        for(int i = 0; i < 26; i++)
            if (rn[i] > mag[i]) 
                return false;
        return true;
    }
    
    void str2Vec(string& str, vector<int>& vec){
        for(char c : str)
            vec[c - 'a']++;
    }
};
