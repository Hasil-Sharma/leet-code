// https://leetcode.com/problems/target-sum/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[20][1001];
    int get_abs(int num){
        return (num > 0) ? num : -1 * num;
    }
    
    int helper(vector<int>& nums, int S, int start){
        int abs_S = this->get_abs(S);
        // if abs_S program wouldn't work and Note #2
        if (abs_S > 1000) return 0;
        else if (start == nums.size()){
            // all the elements of the array has been used
            // Return 1 in case the sum is reached or 0 if it is not reached
            return (S == 0) ? 1 : 0;
        } else if (dp[start][abs_S] > -1) {
            return dp[start][abs_S];
        }
        
        dp[start][abs_S] = this->helper(nums, S - nums[start], start + 1) + this->helper(nums, S + nums[start], start + 1);
        return dp[start][abs_S];
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        for(int i = 0; i < 20; i++)
            for(int j = 0; j <= 1000; j++)
                dp[i][j] = -1;
        return this->helper(nums, S, 0);;
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int S = stringToInteger(line);
        
        int ret = Solution().findTargetSumWays(nums, S);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
