// https://leetcode.com/problems/find-smallest-letter-greater-than-target/description

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<int> hash_table(27, 0);
        char ans = 0;
        for(char c : letters)
            hash_table[c - 'a']++;
        
        target++;
        while(!ans){
            target = (target > 'z') ? 'a' : target;
            ans = (hash_table[target++ - 'a'] > 0) ? --target : ans;
        }
        return ans;
        
        // auto ans = lower_bound(letters.begin(), letter.end(), target);
    }
};

