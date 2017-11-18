// https://leetcode.com/problems/search-for-a-range/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getBound(vector<int>& nums, int target, int flag){
       int start = 0, end = nums.size() - 1, ans = -1, mid;
        
        while(start <= end){
            mid = ( start + end )/2;
            if (target == nums[mid]){
                ans = mid;
                if (flag == 0){
                    // lowerBound
                    end  = mid - 1;
                } else {
                    // upperBound
                    start = mid + 1;
                }
            } else if (target > nums[mid]){
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> answer;
        for(int i = 0; i < 2; i++) answer.push_back(this->getBound(nums, target, i));
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

int stringToInteger(string input) {
    return stoi(input);
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
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        vector<int> ret = Solution().searchRange(nums, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
