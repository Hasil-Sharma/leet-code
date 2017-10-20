// https://leetcode.com/problems/count-binary-substrings/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        char prev_c;
        int ans;
        int hash_array[2];
        
        ans = 0;
        prev_c = '\0';
        hash_array[0] = 0;
        hash_array[1] = 0;
        
        for(char c : s){
            
            if(prev_c != c) hash_array[c - '0'] = 0;
            
            hash_array[c - '0']++;
            
            if (hash_array[0] != 0 && hash_array[1] != 0){
                if (hash_array[0] == hash_array[1]) {
                    ans++;
                }
                
                if (c == '0'){
                    if (hash_array[0] > hash_array[1] && prev_c != '0') ans++;
                    else if (hash_array[0] < hash_array[1]) ans++;
                } else {
                    if (hash_array[0] < hash_array[1] && prev_c != '1') ans++;
                    else if (hash_array[0] > hash_array[1]) ans++;
                }
            }
            
            prev_c = c;
        }
        return ans;
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

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().countBinarySubstrings(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
