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
        
        if (num == 0) 
            return "Zero";
        string ans = "";
        while(num){
            int temp = num % 1000;
            num /= 1000;
            if (!temp) {
                units++;
                continue;
            }
            
            if (units) ans = " "  + units_mappings[units] + ans;
            units++;
            
            if (temp <= 20) ans = " " + num_mappings[temp] + ans;
            else if (temp < 100) {
                if (temp % 10) ans = " "  + num_mappings[temp % 10] + ans;
                ans = " " + num_mappings[(temp / 10) * 10] + ans;
            } else {
                int ttemp = temp % 100;
                if (ttemp <= 20 && ttemp) ans = " " + num_mappings[ttemp] + ans;
                else {
                    if (ttemp % 10) ans = " " + num_mappings[ttemp % 10] + ans;
                    if (ttemp / 10) ans = " " + num_mappings[(ttemp / 10) * 10] + ans;
                }
                ans = " " + num_mappings[(temp/100)] + " Hundred" + ans;
            }
            
        }
        
        return ans.substr(1);
    }
};
