// https://leetcode.com/problems/climbing-stairs/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 2, temp;
         if (n == 1) return a;
        else if (n == 2) return b;
        
        for(int i = 3; i <= n; i++){
            temp = b;
            b = b + a;
            a = temp;
        }
        
        return b;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().climbStairs(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
