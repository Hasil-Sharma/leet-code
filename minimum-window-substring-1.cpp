// https://leetcode.com/problems/minimum-window-substring/description/

typedef unordered_map<int, int> umpii;
class Solution {
public:
    string minWindow(string s, string t) {
        int letterCount = 0, minLen = INT_MAX;
        umpii tmap, wmap;
        string result;
        for(char c : t) 
            tmap[c]++;
        
        for(int i = 0, j = 0; j < s.length(); j++){
            if (tmap.count(s[j])) {
                wmap[s[j]]++;
                if (wmap[s[j]] <= tmap[s[j]])
                    letterCount++;
            }
            
            if (letterCount >= t.length()){
                while(!tmap.count(s[i]) || wmap[s[i]] > tmap[s[i]]){
                    if (wmap.count(s[i])) wmap[s[i]]--;
                    i++;
                }
                
                if (j - i + 1 < minLen){
                    minLen = j - i + 1;
                    result = s.substr(i, minLen);
                }
            }
        }
        return result;
    }
};
