// https://leetcode.com/problems/beautiful-arrangement/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int N, int pos, vector<bool>& used){
        // pos: position to be filled
        int count = 0;
        if (pos > N) return 1;
        
        for(int i = 1; i <= N; i++){
            if (!used[i] && (pos % i == 0 || i % pos == 0)){
                used[i] = true;
                count += this->helper(N, pos + 1, used);
                used[i] = false;
            }
        }
        return count;
    }
    int countArrangement(int N) {
        vector<bool> used(N, false);
        int count = this->helper(N, 1, used);
        return count;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int N = stringToInteger(line);
        
        int ret = Solution().countArrangement(N);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
