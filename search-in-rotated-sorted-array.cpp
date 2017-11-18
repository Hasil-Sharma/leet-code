// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binarySearchMod(vector<int>& nums, int target, int s, int e){
        // s,e are start and end index respectively;
        
        int mid = s + (e - s) / 2; // to avoid overflow if any
        if (nums[mid] == target) return mid;
        
        if (s >= e) return -1; // s >= e because if it is equal that corresponds to same element and if it is not same then it should return - 1
        
        // this means array s to mid is sorted
        if (nums[s] <= nums[mid]){
            if (nums[s] <= target && nums[mid] >= target){
                // target lies between s and mid;
                return this->binarySearchMod(nums, target, s, mid);
            }
            // target lies in the other segment
            return this->binarySearchMod(nums, target, mid + 1, e);
        } 
        
        // if s to mid of nums isn't sorted other part must be sorted
        
        // if target is int this segment
        if (nums[mid] <= target && nums[e] >= target)
            return this->binarySearchMod(nums, target, mid, e);
        // check if target is in other segment
        return this->binarySearchMod(nums, target, s, mid - 1);
    }
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        return (n > 0) ? this->binarySearchMod(nums, target, 0, n - 1) : - 1;
        
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
        int target = stringToInteger(line);
        
        int ret = Solution().search(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
