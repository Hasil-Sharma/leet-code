// https://leetcode.com/problems/palindromic-substrings/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        bool **p; // table to find if i to j is a palindrome
        int **dp; // table to find number of palindromes from i to j dp[0][n-1] has the answer
        p = new bool*[n];
        dp = new int*[n];
        for(int i = 0; i < n; i++){
            p[i] = new bool[n];
            dp[i] = new int[n];
            for(int j = 0; j < n; j++){
                p[i][j] = (i == j) ? true : false; // one character is a palindrome
                dp[i][j] = (i == j) ? 1 : 0; // one character is a palindrome
            } 
            if (i > 0 && s[i - 1] == s[i]){
                p[i - 1][i] = true; // two character palindrome
            }
        }
        
        // getting palindrome of 3, 4,...,n length
        for(int l = 3; l <= n; l++){
            for(int i = 0; i < n - l + 1; i++){
                int j = i + l - 1;
                p[i][j] = (s[i] == s[j]) ? p[i+1][j-1] : false;
            }
        }
        for(int l = 2; l <= n; l++){
            for(int i = 0; i < n - l + 1; i++){
                int j = i + l - 1;
                dp[i][j] = (p[i][j] ? 1 : 0) + dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
            }
        }
        
        return dp[0][n - 1];
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
        
        int ret = Solution().countSubstrings(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
