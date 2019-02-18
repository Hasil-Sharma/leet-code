// https://leetcode.com/problems/license-key-formatting/

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        list<char> ss;
        int n = S.length(), k = 0;
        
        for(int i = n - 1; i >= 0; i--){
            if (S[i] == '-') continue;
            else if (k == K){
                ss.push_front('-');
                k = 0;
            }
            ss.push_front(toupper(S[i]));
            k++;
        }
        
        return string(ss.begin(), ss.end());
    }
};
