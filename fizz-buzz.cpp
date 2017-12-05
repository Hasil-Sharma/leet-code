// https://leetcode.com/problems/fizz-buzz/submissions/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        const string s1 = "Fizz", s2 = "Buzz", s3 = s1 + s2;
        for(int i = 0; i < n; i++){
            bool flag3 = ((i+1) % 3 == 0);
            bool flag5 = ((i+1) % 5 == 0);
            
            ans[i] = (flag3 && flag5) ? s3 : (flag3 ? s1 : (flag5 ? s2 : to_string(i+1)));
        }
        return ans;
    }
};

