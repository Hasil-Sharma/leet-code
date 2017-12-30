// https://leetcode.com/problems/decode-ways/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.length() == 0 || s[0] == '0') return 0;
        int prev_prev = 1, prev = 1, answer;
        
        for(int i = 0; i < s.length(); i++){
            answer = 0;
            if (i > 0 && s[i-1] == '0' && s[i] == '0') 
                return 0;
            if (s[i] != '0') {
                answer = prev;
            }
            if (i > 0 && ((s[i-1] < '2' && s[i-1] > '0') || (s[i-1] == '2' && s[i] < '7'))) {
                answer += prev_prev;
            }
            prev_prev = prev;
            prev = answer;
        }
        
        return answer;
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
        
        int ret = Solution().numDecodings(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
