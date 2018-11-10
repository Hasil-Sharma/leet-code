// https://leetcode.com/problems/reverse-words-in-a-string-ii/

class Solution {
public:
    void reverseWords(vector<char>& str) {
        int s = 0, e = 0, n = str.size();
        
        while(e <= n){
            if (e == n || str[e] == ' '){
                rev(str, s, e - 1);
                s = e + 1;
            }
            e++;
        }
        
        rev(str, 0, n - 1);
    }
    
    void rev(vector<char>& str, int s, int e){
        while(s < e)
            swap(str[s++], str[e--]);
    }
};
