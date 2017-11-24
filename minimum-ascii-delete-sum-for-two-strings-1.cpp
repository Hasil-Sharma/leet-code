// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:    
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length(), n  = s2.length(), cost[m+1][n+1];
        
        memset(cost, 0, (m+1)*(n+1) * sizeof(int));
        
        for(int i = 1; i <= m; i++){
            // Cost of taking  i length s1 and 0 length s2
            cost[i][0] = cost[i-1][0] + s1[i-1];
            for(int j = 1; j <= n; j++){
                // Cost of taking 0 length s1 and j length s2
                cost[0][j] = cost[0][j-1] + s2[j-1];
                cost[i][j] = (s1[i-1] == s2[j-1]) ? cost[i-1][j-1] : min(cost[i-1][j] + s1[i-1], cost[i][j-1] + s2[j-1]);
            }
        }
        return cost[m][n];
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
        string s1 = stringToString(line);
        getline(cin, line);
        string s2 = stringToString(line);
        
        int ret = Solution().minimumDeleteSum(s1, s2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
