// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        int minLen = INT_MAX, n = s.length(), i = 0, j = 0, letterCount = 0;
        string ans;
        unordered_map<char, int> tcount, ccount;
        
        for(char c : t) tcount[c]++;
        
        while(i < n){
            // extending the current sentence
            if (tcount.count(s[i])){
                ccount[s[i]]++;
                letterCount += (tcount[s[i]] >= ccount[s[i]]);
            }

            
            // trimming of the sentence
            if (letterCount >= t.length()){
                while(!tcount.count(s[j]) || ccount[s[j]] > tcount[s[j]]){
                    ccount.count(s[j]) ? ccount[s[j]]-- : -1;
                    j++;
                }
                
                if (i - j + 1 < minLen){
                    minLen = i - j + 1;
                    ans = s.substr(j, minLen);
                }
            }
            
            i++;
            
        }
        
        return ans;
    }
};
