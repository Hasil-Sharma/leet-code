//https://leetcode.com/problems/self-dividing-numbers/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkNum(int num){
        int d, n = num;
        bool flag = true;
        while(n && flag){
            d = n % 10;
            if (d == 0 || num % d != 0) flag = false;
            n /= 10;
        }
        return flag;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> answer;
        while(left <= right) if(this->checkNum(left++)) answer.push_back(left - 1);
        return answer;
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
        int left = stringToInteger(line);
        getline(cin, line);
        int right = stringToInteger(line);
        
        vector<int> ret = Solution().selfDividingNumbers(left, right);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
