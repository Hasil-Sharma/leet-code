//https://leetcode.com/problems/arithmetic-slices/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getAPNumbers(int n){
        return (n - 2)*(n - 1)/2;
    }
    
    int numberOfArithmeticSlices(vector<int>& A) {
        
        // Return 0 if the sizeof vector<int> is less than 3
        if (A.size() < 3) return 0;
        int diff = A[0] - A[1], curLength = 2, ans = 0;
        for(int i = 2; i < A.size(); i++){
            // if the A[i] number is part of AP slice
            if (A[i - 1] - A[i] == diff) curLength++;
            else {
                ans += this->getAPNumbers(curLength);
                diff = A[i - 1] - A[i];
                curLength = 2;
            }
            
        }
        
        ans += this->getAPNumbers(curLength);
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
        
        int ret = Solution().numberOfArithmeticSlices(A);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
