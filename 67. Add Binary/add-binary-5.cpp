// https://leetcode.com/problems/add-binary/description/

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1, j = b.length() - 1, c = 0;
        stringstream ss;
        while(i >= 0 || j >= 0 || c == 1){
            c += i >= 0 ? a[i--] - '0' : 0;
            c += j >= 0 ? b[j--] - '0' : 0;
            ss << string(1, c % 2 + '0');
            c = c/2;
        }
        
        string ans = ss.str();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
