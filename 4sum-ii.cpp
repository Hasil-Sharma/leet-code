//https://leetcode.com/problems/4sum-ii/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void getValueMap(unordered_map <long long int, int>& map, vector<int>& A, vector<int>& B){
        for(long long int a : A)
            for(long long int b : B){
                long long int sum = a + b;
                map[sum] = (map.find(sum) != map.end()) ? map[sum] + 1 : 1;
            }
    }
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map <long long int, int> value_map1, value_map2;
        unordered_map <long long int, int> :: iterator itr1, itr2;
        int ans = 0;
        
        this->getValueMap(value_map1, A, B);
        this->getValueMap(value_map2, C, D);
        
        for(itr1 = value_map1.begin(); itr1 != value_map1.end(); itr1++){
            itr2 = value_map2.find(-1 * itr1->first);
            if(itr2 != value_map2.end()){
                ans += (itr1->second * itr2->second);
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
        vector<int> A = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> B = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> C = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> D = stringToIntegerVector(line);
        
        int ret = Solution().fourSumCount(A, B, C, D);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
