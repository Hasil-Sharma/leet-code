// https://leetcode.com/problems/decode-string/description/

class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        return helper(s, 0, n);
    }
    
    string helper(string &s, int start, int len){
        stringstream ans;
        int num = 0;
        for(int i = start; i < start + len; i++){
            if (isdigit(s[i])) num = num * 10 + (s[i] - '0');
            else if (s[i] == '['){
                int count = 1, j;
                for(j = i + 1; count; j++)
                    count += (s[j] == '[' ? 1 : (s[j] == ']' ? -1 : 0));
                string t = helper(s, i + 1, j - i - 1);
                i = j - 1; // adding extra +1 from the loop
                while(num--)
                    ans << t;
                num = 0;
            } else if (s[i] == ']'){
                continue;
            } else {
                ans << string(1, s[i]);
            }
        }
        return ans.str();
    }
};
