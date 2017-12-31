// https://leetcode.com/problems/valid-palindrome/description/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkValid(char c){
        if((c <= 'z' && c >= 'a') || (c <='9' && c >= '0')) return true;
        return false;
    }
    bool isPalindrome(string s) {
        if (s.length() == 0) return true;
        int start = 0, end = s.length() - 1;
        char cs, ce;
        while(start <= end){
            cs = tolower(s[start]); 
            ce = tolower(s[end]);
            if (!checkValid(cs)) {
                start++;
            } else if (!checkValid(ce)){
                end--;
            } else {
                if(cs == ce){
                    start++; end--;
                } else {
                    return false;
                }
            }
        }
        
        return true;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        bool ret = Solution().isPalindrome(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
