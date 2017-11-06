// https://leetcode.com/problems/longest-common-prefix/description/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s;
        int shortest_len;
        
        if (strs.size() == 0) return "";
        
        s = strs[0];
        for(string c: strs){
            string temp = "";
            shortest_len = min(c.length(), s.length());
            for(int i = 0; i < shortest_len; i++){
                if(s[i] == c[i])
                    temp += s[i];
                else break;
                    
            }
            s = temp;
        }
        return s;
    }
};

