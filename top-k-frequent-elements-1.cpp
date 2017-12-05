// https://leetcode.com/problems/top-k-frequent-elements/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct mypair_comp{
        bool operator()(pair<int, int> const& p1, pair<int, int> const& p2){
            return p1.second < p2.second;
        }
    };
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> nums_count;
        vector<pair<int, int>> elem_vector;
        vector<int> ans;
        for(int num: nums) nums_count[num]++;
        
        for(auto itr: nums_count) elem_vector.push_back(make_pair(itr.first, itr.second));
        
        make_heap(elem_vector.begin(), elem_vector.end(), mypair_comp());
        while(k--){
            ans.push_back(elem_vector.front().first);
            pop_heap(elem_vector.begin(), elem_vector.end(), mypair_comp()); 
            elem_vector.pop_back();
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
        int k = stringToInteger(line);
        
        vector<int> ret = Solution().topKFrequent(nums, k);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
