// https://leetcode.com/problems/maximum-subarray/description/

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <limits.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        return this->maxSubArrayHelper(nums, 0, nums.size() - 1);
    }
    
    int maxSubArrayHelper(vector<int> &nums, int start , int end){
        if(start == end) return nums[start]; // single element call
        int mid = (start + end)/2;
        
        return max(this->maxSubArrayHelper(nums, start, mid),
                  max(this->maxSubArrayHelper(nums, mid + 1, end),
                  this->maxSubArrayCrossing(nums, start, mid, end)));
    }
    
    int maxSubArrayCrossing(vector<int> &nums, int start, int mid, int end){
        int left_sum = INT_MIN, right_sum = INT_MIN;
        int sum;
        for(int i = mid, sum = 0; i >= start; --i){
            sum = sum + nums[i];
            if( sum > left_sum) left_sum = sum;
        }
        
        for(int i = mid + 1, sum = 0; i <= end; ++i){
            sum = sum + nums[i];
            if(sum > right_sum) right_sum = sum;
        }
        
        return left_sum + right_sum;
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
        
        int ret = Solution().maxSubArray(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
