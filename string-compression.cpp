// https://leetcode.com/problems/string-compression/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress_helper(vector<char>& chars, vector<char> :: iterator start, vector<char> :: iterator end){
        
        int sub_len = end - start + 1, len;
        len = sub_len;
        if (sub_len > 1){
            // adding the number
            len = 0;
            // cout << "Sub len:" << sub_len << endl;
            if (sub_len < 10){
                *(++start) = '0' + sub_len;
                len+= 1;
            } else if (sub_len < 100){
                *(++start) = '0' + (sub_len / 10);
                *(++start) = '0' + (sub_len % 10);
                len+= 2;
            } else if (sub_len < 1000){
                *(++start) = '0' + (sub_len / 100);
                *(++start) = '0' + ((sub_len % 100) / 10);
                *(++start) = '0' + (sub_len % 10);
                len += 3;
            } else {
                *(++start) = '1';
                *(++start) = '0';
                *(++start) = '0';
                *(++start) = '0';
                len += 4;
            }
            ++len;
            for(start++ ; start <= end; start++){
                // cout << "Converting reset as NULL" << endl;
                *start = '\0';
            }
        }
        return len;
    }
    
    int compress(vector<char>& chars) {
        
        vector<char> :: iterator itr, start, end;
        int len = 0, sub_len;
         // start points to the first character of segment and end points to the last character in segment;
        start = chars.begin();
        end = chars.begin();
        
        for(itr = chars.begin() + 1; itr != chars.end(); itr++){
            if (*itr == *start) end++;
            else {
                len += this->compress_helper(chars, start, end);
                start = itr;
                end = itr;
            }
        }
        
        len += this->compress_helper(chars, start, end);
        
        itr = chars.begin();
        while (itr != chars.end()){
            if(*itr == '\0' ){
                itr = chars.erase(itr);
            } else itr++;
        }
        return len;
        
    }
};
