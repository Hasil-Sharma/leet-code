// https://leetcode.com/problems/k-diff-pairs-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> value_count;
        map<pair<int, int>, bool> taken;
        int ans = 0, a, b;
        
        for(int num : nums){
            value_count[num]++;
            taken[make_pair(num, num)] = false;
        }
        
        for(int num : nums){
            if (k == 0) {
                ans += (!taken[make_pair(num, num)] && value_count[num] > 1) ? 1 : 0;
                taken[make_pair(num, num)] = true;
            } else {
                taken[make_pair(num, num)] = true;
                for(int i = k; i >= k * -1; i -= 2*k){
                    if ((!taken[make_pair(num + i, num)]) && (value_count.find(num + i) != value_count.end())) {
                        ans += 1;
                        taken[make_pair(num + i, num)]  = true;
                        taken[make_pair(num, num + i)]  = true;
                    }
                }
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        int ret = Solution().findPairs(nums, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
