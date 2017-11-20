// https://leetcode.com/problems/single-element-in-a-sorted-array/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, h = nums.size() - 1, mid, ans, flag = true;
        while((h >= l) && flag){
            mid = (h + l)/2;
            if (mid > 0 && nums[mid] == nums[mid - 1]){
                // go towards odd length segment
                if (mid % 2 == 1) l = mid + 1;
                else h = mid - 2;
            } else if (nums[mid] == nums[mid + 1]) {
                // no need to check mid < nums.size() - 1 given the way mid is calculated
                // go towards odd length segment
                if (mid % 2 == 1) h = mid - 1;
                else l = mid + 2;
            } else {
                ans = nums[mid];
                flag = false;
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
        
        int ret = Solution().singleNonDuplicate(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
