// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        vector<char> temp;
        unordered_map<char, vector<char>> adjList;
        char c = 'a';
        
        for(char i = '2'; i <= '9'; i++){
            int count = 3 + (i == '7' || i == '9');
            while(count--)
                adjList[i].push_back(c++);
        }
        if (digits.length())
            helper(digits, 0, adjList, ans, temp);
        
        return ans;
    }
    
    void helper(string &digits, int idx, unordered_map<char, vector<char>> &adjList, vector<string>& ans, vector<char>& temp){
        if (idx == digits.length()){
            ans.push_back(string(temp.begin(), temp.end()));
            return;
        }
        
        for(char c : adjList[digits[idx]]){
            temp.push_back(c);
            helper(digits, idx + 1, adjList, ans, temp);
            temp.pop_back();
        }
    }
};
