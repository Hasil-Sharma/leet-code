// https://leetcode.com/problems/palindromic-substrings/description/

class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for(int i = 0; i < s.length(); i++){
            ans += count_palindrome(s, i, i);
            ans += count_palindrome(s, i, i + 1);
        }
        return ans;
    }
    
    int count_palindrome(string & s, int prev, int next){
        int count = 0;
        while(prev >= 0 && next < s.length() && s[prev--] == s[next++])
            count++;
        return count;
    }
};
