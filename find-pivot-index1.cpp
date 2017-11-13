// https://leetcode.com/problems/find-pivot-index/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int nums_size = nums.size(), ans = -1, lsum;
        vector<int> sum;
        
        for(int c : nums){
            sum.push_back ( sum.size() == 0 ? c : c + sum.back());
        }
        
        for(int i = 0,  lsum = 0, rsum = 0; i < nums_size && ans < 0; i++){
            lsum = (i > 0) ? sum[i - 1] : 0;
            rsum = sum.back() - sum[i];
            ans = (lsum == rsum) ? i : ans;
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
        
        int ret = Solution().pivotIndex(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
