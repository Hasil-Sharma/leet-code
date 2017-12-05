// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/discuss/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(string& s, int start, int end, int k){
        if (k > end - start) return 0;
        vector<int> hash(26, 0);
        for(int i = start; i < end; i++)
            hash[s[i] - 'a']++;
        
        for(int i = start; i < end; i++){
            if (hash[s[i] - 'a'] < k){
                return max(this->helper(s, start, i, k), this->helper(s, i + 1, end, k));
            }
        }
        return end - start;
    }
    
    int longestSubstring(string s, int k) {
        return this->helper(s, 0, s.length(), k);
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        int ret = Solution().longestSubstring(s, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
