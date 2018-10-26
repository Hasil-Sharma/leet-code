// https://leetcode.com/problems/word-pattern-ii/description/

class Solution {
public:
    unordered_map<char, string> char2Token;
    unordered_set<string> tokens;
    
    bool wordPatternMatch(string pattern, string str) {
        return matching(pattern, 0, str, 0);
    }
    
    bool matching(string& pattern, int i, string& str, int j){
        if (pattern.length() == i && str.length() == j) return true;
        else if (pattern.length() == i || str.length() == j) return false;
        char c = pattern[i];
        
        if(char2Token.count(c)){
            int k = char2Token[c].length();
            if(str.substr(j, k) == char2Token[c])
                return matching(pattern, i + 1, str, j + k);
        } else {
            for(int k = 1; k <= str.length() - j; k++){
                string token = str.substr(j, k);
                if (tokens.count(token)) continue;
                
                char2Token[c] = token;
                tokens.insert(token);
                
                if (matching(pattern, i + 1, str, j + k)) 
                    return true;
                
                char2Token.erase(c);
                tokens.erase(token);
            }
        }
        
        return false;
    }
};
