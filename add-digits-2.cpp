// https://leetcode.com/problems/add-digits/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        if (num % 10 == num) return num;
        for(int i = 1; i < 10; i++){
            if ((num - i) % 9 == 0)
                return i;
        }
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
