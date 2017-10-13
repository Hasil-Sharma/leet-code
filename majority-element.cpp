//https://leetcode.com/problems/majority-element/description/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <assert.h>
using namespace std;
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int nums_size = nums.size();
        int max_element = nums[0];
        int count = 1;
        for(int i = 1; i < nums_size; i++){
            if (count == 0){
                count++;
                max_element = nums[i];
            }
            else if(nums[i] == max_element) count++;
            else if (nums[i] != max_element) count--;
        }
        return max_element;
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
        
        int ret = Solution().majorityElement(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
