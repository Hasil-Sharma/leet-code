// https://leetcode.com/problems/decode-string/description/

class Solution {
public:
    
    int start = 0;
    
    bool is_num(char c){
        return c >= '0' && c <= '9';
    }
    
    void extract_number(string& s, string& number){
        while(is_num(s[start]))
            number += s[start++];
    }

    string decodeString(string s) {
        // extract the number
        // skip the '['
        // extract the string afterwards till a digit is encountered
        // recurse
        string ans = "";
        while(start < s.length()){
            string number = "";
            int k;
            extract_number(s, number);
            // cout << start << " number: " << number << endl;
            // start now points to a opening bracket
            k = number != "" ? stoi(number) : 0;
            if (k == 0){
                // no number was found
                string temp = "";
                // copy the string till the time a number is found
                // cannot encounter a open bracket without encountering a number
                // 
                while(start < s.length() && !is_num(s[start]) && s[start] != ']')
                    ans += s[start++];
                if (s[start] != ']')
                    ans = ans + decodeString(s);
                else{
                    start++; // go next from ']'
                }
                return ans;
            } else {
                // start points to '['
                ++start;
                string temp = decodeString(s);
                while(k--)
                    ans += temp;
            }
        }
        
        return ans;
    }
};
