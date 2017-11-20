//https://leetcode.com/problems/palindromic-substrings/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

  int count(int s, int e, int** dp, bool** p)
  {
    if (s < 0 || e < 0 || s > e)
      return 0;
    else if (dp[s][e] > 0)
      return dp[s][e];
    dp[s][e] = (p[s][e] ? 1 : 0) + this->count(s + 1, e, dp, p) + this->count(s, e - 1, dp, p) - this->count(s + 1, e - 1, dp, p);
    return dp[s][e];
  }

  int countSubstrings(string s)
  {
    int n = s.length();
    int **dp;
    bool **p;
    dp = new int*[n];
    p = new bool*[n];
      
    for (int i = 0; i < n; i++) {
        dp[i] = new int[n];
        p[i] = new bool[n];
      for (int j = 0; j < n; j++) {
        dp[i][j] = (i == j) ? 1 : 0;
        p[i][j] = (i == j) ? true : false; // palindrome of length 1
      }
    }
    
      // palindrome of length 2
    for (int i = 1; i < n; i++){
        if (s[i] == s[i - 1]) {
            p[i - 1][i]  = true;
        }
    }
      
    for (int l = 3; l <= n; l++) {
      for (int i = 0; i < n; i++) {
        int j = i + l - 1;
        if (j >= n)
          continue;
        p[i][j] = (s[i] == s[j]) ? p[i + 1][j - 1] : false;
      }
    }

    return this->count(0, n - 1, dp, p);
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
