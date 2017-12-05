// https://leetcode.com/problems/daily-temperatures/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minIdx(vector<vector<int>> & dp, int temp, int index){
        int min_j = INT_MAX;
        vector<int>& v = dp[temp];
        
        if (v.size() != 0) {
            auto up = upper_bound(v.begin(), v.end(), index);
            if (up != v.end()) return *up;
        }
        return -1;
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int max_temp = 101, n = temperatures.size();
        vector<vector<int>> dp(max_temp, vector<int>());
        vector<int> answer(n, INT_MAX);
        
        for(int i = 0; i < n; i++)
            dp[temperatures[i]].push_back(i);
        
        for(int i = 0; i < n; i++){
            for(int temp = temperatures[i] + 1; temp < max_temp; temp++){
                int j = this->minIdx(dp, temp, i);
                if (j == -1) continue;
                else answer[i] = min(answer[i], j - i);
            }
            answer[i] = (answer[i] == INT_MAX) ? 0 : answer[i];
        }
        return answer;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
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
        vector<int> T = stringToIntegerVector(line);
        
        vector<int> ret = Solution().dailyTemperatures(T);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
