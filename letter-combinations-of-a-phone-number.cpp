//https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map <char, string> num_letter_map = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };
        vector<string> answer;
        bool flag;
        
        for(char c : num_letter_map[digits[0]]) {
            string temp;
            temp.push_back(c);
            answer.push_back(temp);
        }
        
        digits.erase(0,1);
        
        for (char c : digits){
            vector<string> temp;
            flag = false;
            for( char t : num_letter_map[c]){
                flag = true;
                for (string v : answer){
                    v.push_back(t);
                    temp.push_back(v);
                }
            }
            // In case number in digist doesn't exist
            if (flag == false) return temp;
            answer = temp;
        }
        
        return answer;
    }
};
