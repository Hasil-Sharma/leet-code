// https://leetcode.com/problems/add-digits/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int ans = num;
        while(num % 10 != num){
            ans = 0;
            while(num){
                ans += num % 10;
                num /= 10;
            }
            num = ans;
        }
        return ans;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);
        
        int ret = Solution().addDigits(num);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
