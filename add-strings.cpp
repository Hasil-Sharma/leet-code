// https://leetcode.com/problems/add-strings/description/

class Solution {
public:
    string addStrings(string num1, string num2) {
        // write your code here
        string ans = "";
        int carry = 0, i = num1.length() - 1, j = num2.length() - 1, temp;
        
        while(i >= 0 || j >= 0){
            temp = (i >= 0 ? num1[i--] - '0' : 0) + (j >= 0 ? num2[j--] - '0' : 0) + carry;
            carry = temp / 10;
            char c = temp % 10 + '0';
            ans = c + ans;
        }
        
        if (carry)
            ans = '1' + ans;
        return ans;
    }
};
