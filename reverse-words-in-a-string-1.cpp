// https://leetcode.com/problems/reverse-words-in-a-string/description/

class Solution {
private:
    void reverse(string &s, int i, int j){
        while(i < j)
            swap(s[i++], s[j--]);
    }
public:
    void reverseWords(string &s) {
        reverse(s, 0, s.length() - 1);
        int start = 0, end;
        for(end = 0; end < s.length(); end++){
            if (s[end] == ' ') {
                reverse(s, start, end - 1);
                start = end + 1;
            }
        }
        
        reverse(s, start, end - 1);
        
        int i = 0, j = 0;
        
        // removing starting spaces
        while(j < s.length() && s[j] == ' ') j++;
        
        // removing spaces from inbetween
        while(j < s.length()){
            if(j > 0 && s[j] == s[j-1] && s[j] == ' '){
                j++;
            } else {
                s[i++] = s[j++];
            }
        }
        // removing trailing spaces
        if (s[i - 1] == ' ') i--;
        s[i] = '\0';
    }
};
