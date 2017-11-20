// https://leetcode.com/problems/2-keys-keyboard/discuss/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        if (n == 1) return ans;
        for(int i = 2; i <= sqrt(n); i++){
            while(n % i == 0){
                ans += i;
                n /= i;
            }
        }
        return (n > 1) ? ans + n : ans;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().minSteps(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
