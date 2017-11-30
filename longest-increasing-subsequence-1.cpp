// https://leetcode.com/problems/longest-increasing-subsequence/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n);
    
        for(int i = 0; i < n; i++) dp[i] = 1;         
        
        // adding ith element to all the elements before it
        for(int i = 1; i < n; i++)
            for(int j = 0; j < i; j++)
                if (nums[i] > nums[j]) dp[i] = max(dp[i], 1 + dp[j]);
        
        return *max_element(dp.begin(), dp.end());
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
        
        int ret = Solution().lengthOfLIS(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
