// https://www.lintcode.com/problem/add-binary/description

class Solution {
public:
    /**
     * @param a: a number
     * @param b: a number
     * @return: the result
     */
    string addBinary(string &a, string &b) {
        // write your code here
        if (b.length() > a.length()) swap(a, b);
        int m = a.length() - 1, n = b.length() - 1, carry = 0;
        
        stringstream ss;
        while(n > -1){
            if (a[m] == b[n]){
                ss << (carry ? '1' : '0');
                carry = a[m] == '1';
            } else {
                ss << (carry ? '0' : '1');
            }
            m--;
            n--;
        }
        
        while(m > -1){
            if (a[m] == '0'){
                ss << (carry ? '1' : '0)';
                carry = 0;
            } else {
                ss << (carry ? '0' : '1');
            }
            m--;
        }
        if (carry) ss << '1';
        auto ans = ss.str();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
