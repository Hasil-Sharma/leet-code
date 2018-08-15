// https://leetcode.com/problems/integer-to-english-words/description/

class Solution {
public:
    unordered_map <int, string> dmap, tmap, pmap;
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        dmap = {
             {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, 
            {9, "Nine"}, {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, 
            {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}
        };
        
        tmap = {
            {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, 
            {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}, {100, "Hundred"}
        };
        
        pmap = {
            {1000, "Thousand"}, {1000000, "Million"}, {1000000000, "Billion"}
        };
        
        string ss = "";
        int p = 1;
        while(num){
            int t = num % 1000;
            num = num / 1000;
            
            if (t) ss = helper(t) + (pmap.count(p) ? " " + pmap[p] + ( ss.length() ? " " + ss : "") : "");
            p = p * 1000;
        }
        
        return ss;
    }
    
    string helper(int num){
        int p = 1;
        string ss = "";
        if (num % 100 < 20){
            ss = dmap[num % 100];
            num /= 100;
            p = 100;
        }
        
        while(num){
            int t = num % 10;
            num = num / 10;
            if (t && p == 1) ss = dmap[t];
            else if (t && p == 10) ss = tmap[t*p] + (ss.length() ? " " + ss: "");
            else if (t && p == 100) ss = dmap[t] + " " + tmap[p] + (ss.length() ? " " + ss : "");
            p = p * 10;
        }
        return ss;
    }
};
