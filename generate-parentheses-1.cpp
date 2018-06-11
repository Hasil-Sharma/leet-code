// https://leetcode.com/problems/generate-parentheses/description/

class Solution {
public:
    vector<string> ans;
    
    void helper(int n, vector<char>& temp, int t, int c, int idx){
        
        if (t == n){
            
            while(c--)
                temp[idx++] = ')';
            ans.push_back(string(temp.begin(), temp.end()));
            return;
            
        } else if (t < n){
            
            temp[idx] = '(';
            helper(n, temp, t + 1, c + 1, idx + 1);
            
            if (c > 0){
                temp[idx] = ')';
                helper(n, temp, t, c - 1, idx + 1);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<char> temp(n << 1, '(');
        int totalOpen = 1, currentOpen = 1;
        helper(n, temp, totalOpen, currentOpen, 1);
        cout << ans.size() << endl;
        return ans;
    }
};
