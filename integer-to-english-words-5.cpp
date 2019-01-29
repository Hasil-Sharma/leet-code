// https://leetcode.com/problems/integer-to-english-words/description/

class Solution {
public:
    unordered_map<int, string> map = {{1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"},
                                          {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"},
                                          {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"},
                                          {18, "Eighteen"}, {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, 
                                      {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}};

    string convert(int temp){
        if (map.count(temp)) return map[temp];
        else if (temp % 100 == 0) return convert(temp/100) + " Hundred";
        else if (map.count(temp % 100)) return convert(temp/100) + " Hundred " + map[temp % 100];
        else if (map.count(temp % 10)) return convert(temp - temp%10) + " " + map[temp % 10];
        else return convert(temp/10);
    }
    
    string numberToWords(int num) {
        string ans = "";
        int c = 0;
        unordered_map<int, string> aux = {{1, " Thousand"}, {2, " Million"}, {3, " Billion"}};
        if (num == 0) return "Zero";
        while(num){
            int temp = num % 1000;
            num = num/1000;
            if (temp){
                ans = convert(temp) + (aux.count(c) ? aux[c] : "") + (ans.length() ? " " : "") + ans;
            }
            c++;
        }
        
        return ans;
    }
};
