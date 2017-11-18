// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int start = 0, end = nums.size() - 1, mid, answer = nums[0];
        
        // start == end in case of one element array
        while(start <= end){
            
            mid = (start + end)/ 2;
            // start to mid must be sorted
            if (nums[start] <= nums[mid]){
                
                if (nums[start] < answer){
                    answer = nums[start];
                    // check in the other segment
                }
                
                start = mid + 1;
                end = end;
            } else {
              // mid to end must be sorted 
                if (nums[mid] < answer){
                    answer = nums[mid];
                }
                
                start = start;
                end = mid - 1;
            }
        }
        
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
