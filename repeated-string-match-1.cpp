// https://leetcode.com/problems/repeated-string-match/description/

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int n = 1, len = A.length();
        
        stringstream ss;
        ss << A;
        
        while(len < B.length()){
            ss << A;
            len += A.length();
            n += 1;
        }
        
        if (ss.str().find(B) != string::npos) return n;
        
        ss << A;
        
        if (ss.str().find(B) != string::npos) return n + 1;
        return -1;
    }
};
