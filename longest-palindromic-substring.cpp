#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";
        int string_len = s.length(),  max_length, start_idx;
        bool dp[string_len][string_len];
        
        memset(dp, false, sizeof(dp));
        // dp[i][j] is true if substring s_i to s_j is palindrome
        
        // All substrings of length 1 are palindrome by default
        max_length = 1;
        start_idx = 0;
        for(int i = 0; i < string_len; i++)
            dp[i][i] = true;
        
        // Checking all substrings of length 2 are palindrome by default
        for(int i = 0; i < string_len - 1; i++ ) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                max_length = 2;
                start_idx = i;
            }
            else dp[i][i+1] = false;
        }
        
        
        // checking string of length k
        for(int k = 3; k <= string_len; k++){
            for(int i = 0; i < string_len; i++){
                int j = i + k - 1;
                
                if (j >= string_len) break;
                
                if (dp[i+1][j-1] && s[i] == s[j]) {
                    dp[i][j] = true; 
                    
                    if(max_length < k){
                        max_length = k;
                        start_idx = i;
                    }
                }
            }
        }
        
        return s.substr(start_idx, max_length);
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
        
        string ret = Solution().longestPalindrome(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
