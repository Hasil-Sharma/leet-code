// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if (s.length() == 0) return 0;
        
        unordered_map <char, int> hashMap;
        unordered_map <char, int> :: iterator itr;
        int startIdx = 0, endIdx = 0, tempLen = 0, resultLen = 0;
        
        hashMap[s[0]] = 0;
        resultLen = 1;
        
        for(int i = 1; i < s.length(); i++){
            itr = hashMap.find(s[i]);
            if (itr == hashMap.end() || itr->second < startIdx){
                // The character is encountered for the first time or character was encountered previously
                hashMap[s[i]] = i;
                endIdx = i;
                
                tempLen = endIdx - startIdx + 1;
                resultLen = (tempLen > resultLen) ? tempLen : resultLen;
                
            } else {
                // The character was encountered before in current range and it can no longer be part of substring
                if (itr->second >= startIdx)
                    startIdx = hashMap[s[i]] + 1;
                hashMap[s[i]] = i;
            }
        }
        
        return resultLen;
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

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
