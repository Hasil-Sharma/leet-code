//https://leetcode.com/problems/partition-equal-subset-sum/description/
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartitionHelper(vector<int>& nums, int nums_size, int subset_sum, int req_sum, int upper_limit, bool *taken){
        int temp;
        bool next;
        
        if (subset_sum == req_sum) return true;
        
        for(int i = upper_limit; i >= 0; i--){
            if (taken[i]) continue;
            
            temp = subset_sum + nums[i];
            if(temp <= req_sum){
                
                taken[i] = true;
                subset_sum += nums[i];
                
                next = this->canPartitionHelper(nums, nums_size, subset_sum, req_sum, i - 1, taken);
                    
                taken[i] = false;
                subset_sum -= nums[i];
                if(next) return true;
            }
        }
        return false;
        
    }
    bool canPartition(vector<int>& nums) {
        int nums_size = nums.size();
        int subset_sum = 0, nums_sum = 0;
        bool taken[nums_size];
        
        for(int i = 0; i < nums_size; i++){
            taken[i] = false;
            nums_sum += nums[i];
        }
        
        if(nums_sum % 2 != 0) return false;
        
        subset_sum = nums[nums_size - 1];
        taken[nums_size - 1] = true;
        
        return this->canPartitionHelper(nums, nums_size, subset_sum, nums_sum / 2, nums_size - 1, taken);
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        bool ret = Solution().canPartition(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
