// https://leetcode.com/problems/counting-bits/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        // num is non-negative that is it is atleast 0
        vector<int> ans(num+1);
        int a = 1, b = 2;
        ans[0] = 0;
        // a is the power of 2 which is smaller than current number 
        // https://stackoverflow.com/questions/20200295/removing-first-bit
        for(int i = 1; i < num + 1; i++){
            
            if (b < i){
                a = b;
                b = b << 1;
            }
            
            ans[i] = 1 + ans[i & (~a)];
        }
        
        return ans;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);
        
        vector<int> ret = Solution().countBits(num);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
