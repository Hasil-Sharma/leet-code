// https://leetcode.com/problems/letter-combinations-of-a-phone-number/


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        unordered_map<char, vector<char>> mapping;
        vector<char> temp;
        char v = 'a'; 
        int count;
        
        for(char i = '2'; i <= '9'; i++){
            count = 3 + (i == '7' || i == '9');
            while(count--){
                mapping[i].push_back(v++);
            }
        }
        
        int n = digits.size();
        if (!n) return ans;
        backtrack(digits, mapping, ans, 0, temp);
        return ans;
    }
    
    void backtrack(string& digits, unordered_map<char, vector<char>>& mapping, vector<string>& ans, int idx, vector<char>& temp){
        if (idx == digits.size()){
            ans.push_back(string(temp.begin(), temp.end()));
            return;
        }
        
        for(char c : mapping[digits[idx]]){
            temp.push_back(c);
            backtrack(digits, mapping, ans, idx + 1, temp);
            temp.pop_back();
        }
    }
};
