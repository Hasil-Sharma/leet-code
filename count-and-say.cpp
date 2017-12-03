// https://leetcode.com/problems/count-and-say/discuss/
// https://www.careercup.com/question?id=4425679
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        if(n == 1) return s;
        
        for(int i = 1; i < n; i++){
            char c = s[0];
            int count = 1;
            stringstream ans;
            
            for(int i = 1; i < s.length(); i++){
                if (s[i] == c) count++;
                else {
                    ans << count << c;
                    c = s[i];
                    count = 1;
                }
            }
            ans << count << c;
            s = ans.str();
        }
        return s;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        string ret = Solution().countAndSay(n);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
