// https://leetcode.com/problems/complex-number-multiplication/discuss/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int a1,a2,b1,b2;
        char buff;
        stringstream aa(a), bb(b), ans;
        aa >> a1 >> buff >> b1 >> buff;
        bb >> a2 >> buff >> b2 >> buff;
        ans << a1 * a2 - b1 * b2 << "+" << a1 * b2 + a2 * b1 << "i";
        return ans.str();
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
        string a = stringToString(line);
        getline(cin, line);
        string b = stringToString(line);
        
        string ret = Solution().complexNumberMultiply(a, b);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
