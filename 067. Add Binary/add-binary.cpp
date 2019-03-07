// https://leetcode.com/problems/add-binary/description/

class Solution {
public:
    
    void finish(int idx, string& a, string& ans, int &carry){
        while(idx >= 0){
            if (a[idx] == '1') ans = (carry ? "0" : "1") + ans;
            else {
                ans = (carry ? "1" : "0") + ans;
                carry = 0;
            }
            idx--;
        }
    }
    string addBinary(string a, string b) {
        int idx1 = a.length() - 1, idx2 = b.length() - 1, carry = 0;
        string ans = "";
        
        while(idx1 >= 0 && idx2 >= 0){
            if(a[idx1] == '1' && b[idx2] == '1'){
                ans = (carry ? "1" : "0") + ans;
                carry = 1;
            } else if (a[idx1] == '1' || b[idx2] == '1') {
                ans = (carry ? "0" : "1") + ans;
                
            } else {
                ans = (carry ? "1" : "0") + ans;
                carry = 0;
            }
            --idx1; --idx2;
        }
        
        if(idx1 >= 0) finish(idx1, a, ans, carry);
        else if (idx2 >= 0) finish(idx2, b, ans, carry);
        if (carry) ans = "1" + ans;
        return ans; 
    }
};
