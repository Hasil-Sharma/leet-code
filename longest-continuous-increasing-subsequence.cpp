// https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int ans = 1, temp = 1;
        
        for(int i = 1; i < nums.size(); i++){
            if (nums[i-1] < nums[i]){
                ans = max(++temp, ans);
            } else {
                temp = 1;
            }
        }
        
        return ans;
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().findLengthOfLCIS(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
