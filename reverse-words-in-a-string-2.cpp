// https://leetcode.com/problems/reverse-words-in-a-string/description/

class Solution {
public:
    void reverseWords(string &s) {
        stringstream ss(s);
        string token, ans = "";
        
        while(ss >> token)
            ans = " " + token + ans;
        
        if (ans.length() > 0) s =  ans.substr(1);
        else s = ans;
    }
};
