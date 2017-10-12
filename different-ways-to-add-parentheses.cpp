// https://leetcode.com/problems/different-ways-to-add-parentheses/description/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <assert.h>
using namespace std;


class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res1, res2, result;
        bool flag = true;
        for(int i = 1; i < input.size(); i ++){
            if(input[i] == '*' || input[i] == '+' || input[i] == '-'){
                flag = false;
                res1 = this->diffWaysToCompute(input.substr(0, i));
                res2 = this->diffWaysToCompute(input.substr(i+1));
                for(int j = 0; j < res1.size(); j++)
                  for(int k = 0; k < res2.size(); k++){
                    result.push_back(this->getResult(res1[j], res2[k], input[i]));
                  }
            }
        }
        if (flag) result.push_back(stoi(input));
        return result;
    }

    int getResult(int a, int b, char op){
      if(op == '*') return a * b;
      else if (op == '+') return a + b;
      else if (op == '-') return a - b;
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    string result;
    if (length == 0) {
        return result;
    }

    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return result.substr(0, result.length() - 2);
}

int main() {
    string line;
    while (getline(cin, line)) {
        string input = stringToString(line);
        
        vector<int> ret = Solution().diffWaysToCompute(input);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
