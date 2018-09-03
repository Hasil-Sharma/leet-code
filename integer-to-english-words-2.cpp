// https://leetcode.com/problems/integer-to-english-words/description/

class Solution {
private:
    unordered_map<int, string> mapping = {
            {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, 
            {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"},
            {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, 
            {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"},
            {18, "Eighteen"}, {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"}, 
            {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"},
            {80, "Eighty"}, {90, "Ninety"}, {100, "Hundred"}, {1000, "Thousand"}, 
            {1000000, "Million"}, {1000000000, "Billion"}
        };

    string convert(int n){
        int temp = 0, i = 0;
        string ans = "";
        if (n && n < 21) return mapping[n];
        int h = n / 100, t = n % 100;
        
        if (t && t < 21) ans = mapping[t];
        else if (t){
            int a = t/10, b = t%10;
            if (a && b) ans = mapping[a*10] + " " + mapping[b];
            else if (a) ans = mapping[a*10];
            else if (b) ans = mapping[b];
        }
        
        if (h) ans = mapping[h] + " " + mapping[100] + (ans.size() ? " " + ans: "");
        
        return ans;
    }
    
public:
    string numberToWords(int num) {
        
        string ans = "";
        if (num == 0) return "Zero";
        
        int i = 1;
        
        while(num){
            int temp = num % 1000;
            num = num / 1000;
            string str = convert(temp);
            if (i != 1 && str.size())
                ans = str + " " + mapping[i] + (ans.size() ? " " + ans : "");
            else if (str.size()) ans = str;
            i = i * 1000;
        }
        
        return ans;
    }
};
