// https://leetcode.com/problems/add-binary/description/

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.length() - 1, n = b.length() - 1, carry = 0;
        stringstream ans;
        if (m < n){
            swap(a, b);
            swap(m, n);
        }
        
        while(n >= 0){
            int i = a[m--] - '0', j = b[n--] - '0';
            if (i == j){
                ans << (0 + carry);
                carry = i;
            } else {
                ans << (carry ? 0 : 1);
            }
        }
        
        while(m >= 0){
            int i = a[m--] - '0';
            if (i == 1){
                if (carry) ans << 0;
                else {
                    ans << 1;
                    carry = 0;
                }
            } else if (i == 0) {
                if (carry) {
                    ans << 1;
                    carry = 0;
                }
                else ans << 0;
            }
        }
        if (carry) ans << 1;
        string aa = ans.str();
        reverse(aa.begin(), aa.end());
        return aa;
    }
};
