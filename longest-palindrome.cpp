// https://leetcode.com/problems/longest-palindrome/description/

class Solution {
public:
    int longestPalindrome(string s) {
        // longest palindrome - largest odd number, all the evens and rest of the odds less one
        vector<int> hash(60, 0);
        int ans = 0, temp = 0, m;
        
        for(char &c : s){
            ++hash[c-'A'];
        }
        
        for(auto &m : hash){
            ans += m - m % 2;
            if (m % 2 == 1 && temp == 0){
                ans += 1;
                temp = m;
            }
        }
        
        return ans;
    }
};
