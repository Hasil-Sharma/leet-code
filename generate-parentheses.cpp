// https://leetcode.com/problems/generate-parentheses/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValid(char *str, int len){
        stack<char> stck;
        
        stck.push(str[0]);
        for(int i = 1; i < len; i++){
            if (str[i] == ')' && stck.top() == '(') stck.pop();
            else stck.push(str[i]);
        }
        
        return stck.empty();
    }
    
    void generateParenthesisAdd(vector<string> &answer, char *temp, int curlen, int len){
        
        if(curlen == len){
            // Required length of temp reached;
            if (this->checkValid(temp, curlen)) answer.push_back(string(temp));
        } else if (curlen % 2 == 1 || !this->checkValid(temp, curlen)){
            // Add both open and close parenthesis
            temp[curlen] = '(';
            this->generateParenthesisAdd(answer, temp, curlen + 1, len);
            temp[curlen] = ')';
            this->generateParenthesisAdd(answer, temp, curlen + 1, len);
            
        } else {
            // Add only open paranthesis
            temp[curlen] = '(';
            this->generateParenthesisAdd(answer, temp, curlen + 1, len);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        
        char temp[2*n + 1];
        
        // Required for correct char array to string conversion
        memset(temp, 0, (2*n + 1)*sizeof(char));
        temp[0] = '(';
        
        this->generateParenthesisAdd(answer, temp, 1, 2*n);
        return answer;
    }
};

