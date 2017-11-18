//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinHelper(vector<int> & nums, int s, int e){
        if (s > e) return INT_MAX;
        
        int mid = (e + s) / 2, curr_min = nums[s];
        if (nums[s] <= nums[mid]){
            // array from s to mid is sorted
            
            // if nums[s] < curr_min than either nums[s] is min or min is in other (non - sorted) segment
            if ( nums[s] < curr_min) return min(nums[s], this->findMinHelper(nums, mid + 1, e));
            
            // min might be in other segment
            return min(curr_min, this->findMinHelper(nums, mid + 1, e));
        }
        
        // mid to e will be definitely sorted if s to mid isn't
        
        // if nums[mid] < curr_min then nums[mid] is min or min is the other (non - sorted) segment
        if (nums[mid] < curr_min) return min(nums[mid], this->findMinHelper(nums, s , mid - 1));
        return min(curr_min, this->findMinHelper(nums, mid + 1, e));
        
    }
    int findMin(vector<int>& nums) {
        return this->findMinHelper(nums, 0, nums.size() - 1);
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
        
        int ret = Solution().findMin(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
