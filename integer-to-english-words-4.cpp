// https://leetcode.com/problems/integer-to-english-words/description/

class Solution {
public:
    string numberToWords(int num) {
        unordered_map<int, string> num_mappings = {
            {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"},
            {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"},
            {18, "Eighteen"}, {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"},
            {80, "Eighty"}, {90, "Ninety"}
        }, units_mappings = {
            {1, "Thousand"}, {2, "Million"}, {3, "Billion"}
        };
        
        int units = 0;
        if (num == 0) return "Zero";
        string ans = "";
        
        while(num){
            int temp = num % 1000;
            num /= 1000;
            if(temp) {
                if (units) ans = " " + units_mappings[units] + ans;
                num2str(temp, ans, num_mappings);
            }
            units++;
        }
        
        return ans.substr(1);
    }
    
    void num2str(int num, string& ans, unordered_map<int, string>& mapping){
        int u, t, h;
        t = num % 100;
        if (num && num <= 20) ans = " " + mapping[num] + ans;
        else if (t <= 20 && t) ans = " " + mapping[t] + ans;
        else {
            u = num % 10;
            if (u) ans = " " + mapping[u] + ans;
            t = num % 100 - u;
            if (t) ans = " " + mapping[t] + ans;
        }
        
        h = num / 100;
        if (h) ans = " " + mapping[h] + " Hundred" + ans;
    }
};
