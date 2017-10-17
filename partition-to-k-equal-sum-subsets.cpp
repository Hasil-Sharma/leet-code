// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartitionKSubsetsHelper(vector<int> & nums, int *subsetSum, bool* taken, int subset, int K, int N, int curIdx, int limitIdx){
        int temp;
        bool next;
        
        if(subsetSum[curIdx] == subset){
            
            if(curIdx == K - 2) return true;
            
            return this->canPartitionKSubsetsHelper(nums, subsetSum, taken, subset, K, N, curIdx + 1, N - 1);
        }
        
        for(int i = limitIdx; i >= 0; i--){
            
            if(taken[i]) continue;
            
            temp = subsetSum[curIdx] + nums[i];
            
            if(temp <= subset){
                
                subsetSum[curIdx] += nums[i];
                taken[i] = true;
            
                next = this->canPartitionKSubsetsHelper(nums, subsetSum, taken, subset, K, N, curIdx, i - 1);
                
                taken[i] = false;
                subsetSum[curIdx] -= nums[i];
                
                if(next) return true;
            }
        }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int subsetSum[k], nums_sum, subset;
        int nums_size = nums.size();
        bool taken[nums_size];
        
        if (k == 1) return true;
        
        nums_sum = 0;
        for(int i = 0; i < nums_size; i++){
            taken[i] = false;
            nums_sum += nums[i];
        }
        for(int i = 0; i < k ; i++)
            subsetSum[i] = 0;
        
        if(nums_sum % k != 0) return false;
        
        subset = nums_sum / k;
        
        // subsetSum[0] = nums[nums_size - 1];
        // taken[nums_size - 1] = true;
        
        return this->canPartitionKSubsetsHelper(nums, subsetSum, taken, subset, k, nums_size, 0, nums_size - 1);
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        bool ret = Solution().canPartitionKSubsets(nums, k);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
