// https://leetcode.com/problems/valid-number/

class Solution {
public:
    bool isNumber(string s) {
        int dot = 0;
        int i = 0, n = s.length();
        
        i = skipspaces(s, i);
        i = (i < n && s[i] == '-' || s[i] == '+') ? i + 1 : i;
        
        if (s[i] == 'e' || i == n || (s[i] == '.' && i + 1 == n) || (s[i] == '.' && i + 1 < n && !isdigit(s[i + 1]))) return false;
        
        i = skipdec(s, i);
        
        if (i == n) return true;
        
        if (s[i] == 'e'){
            i++;
            i = (i < n && s[i] == '-' || s[i] == '+') ? i + 1 : i;
            int prev = i;
            if (i == n) return false;
            i = skipnumbers(s, i);
            if (i == n) 
                return true;
            else if (prev == i) return false;
        } 
        
        if (s[i] == ' '){
            i = skipspaces(s, i);
            return i == n;
        }
        
        return false;
    }
    
    int skipspaces(string& s, int i){
        while(i < s.length() && s[i] == ' ') i++;
        return i;
    }
    
    int skipnumbers(string& s, int i){
        while(i < s.length() && isdigit(s[i])) i++;
        return i;
    }
    
    int skipdec(string&s, int i){
        i = skipnumbers(s, i);
        if (s[i] == '.') {
            i++;
            i = skipnumbers(s, i);
        }
        return i;
    }
};
