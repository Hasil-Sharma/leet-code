// https://leetcode.com/problems/add-binary/description/

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.length(), n = b.length(), carry = 0;
        if (m < n) {
            swap(a, b);
            swap(m, n);
        }
        int j = n - 1, i = m - 1;
        stringstream ss;
        
        while(i >= 0 && j >= 0){
            if (a[i] == b[j]){
                ss << string(1, carry ? '1' : '0');
                carry = (a[i] == '1');
            } else 
                ss << string(1, carry ? '0' : '1');
            i--; j--;
        }
        
        while(i >= 0) {
            if (a[i] == '0') {
                ss << string(1, carry ? '1' : '0');
                carry = 0;
            } else 
                ss << string(1, carry ? '0' : '1');
            i--;
        }
        
        if (carry) ss << string(1, '1');
        string ans = ss.str();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
