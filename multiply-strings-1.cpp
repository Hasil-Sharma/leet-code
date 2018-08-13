// https://leetcode.com/problems/multiply-strings/description/

class Solution {
public:
    string multiply(string num1, string num2) {
        int offset = 0;
        string ans = "";
        if (num1 == "0" || num2 == "0") return "0";
        
        for(int i = num1.length() - 1; i >= 0; i--){
            char c = num1[i];
            string temp = multiply(num2, c - '0');
            ans = add(ans, temp, offset);
            ++offset;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    string multiply(string& num, int n){
        string ss = "";
        int carry = 0, m, temp;
        
        for(int i = num.length() - 1; i >= 0; i--){
            m = num[i] - '0';
            temp = m * n + carry;
            ss = ss + to_string(temp % 10);
            
            carry = temp / 10;
        }
        if (carry) ss = ss + to_string(carry);
        return ss;
    }
    
    string add(string& s1, string &s2, int offset){
        string ss = "";
        int i = 0, j = 0, m = s1.length(), n = s2.length(), carry = 0, temp, p, q;
        while(i < offset)
            ss  = ss + string(1, s1[i++]);
        
        while(i < m && j < n){
            p = s1[i++] - '0'; q = s2[j++] - '0';
            temp = p + q + carry;
            ss = ss + to_string(temp % 10);
            carry = temp / 10;
        }
        
        finish(s1, i, ss, carry);
        finish(s2, j, ss, carry);
        
        if (carry) ss = ss + to_string(carry);
        return ss;
    }
    
    void finish(string& s, int i, string& ss, int& carry){
        int n = s.length(), temp;
        while(i < n){
            int p = s[i++] - '0';
            temp = p + carry;
            ss = ss + to_string(temp % 10);
            carry = temp / 10;
        }
    }
    
};
