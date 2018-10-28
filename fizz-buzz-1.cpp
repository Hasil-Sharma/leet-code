// https://leetcode.com/problems/fizz-buzz/description/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        
        for(int i = 1; i <= n; i++){
            string temp = "";
            if (i % 3 == 0) temp = temp + "Fizz";
            if (i % 5 == 0) temp = temp + "Buzz";
            if (temp.length() == 0) temp = to_string(i);
            ans.push_back(temp);
        }
        return ans;
    }
};
