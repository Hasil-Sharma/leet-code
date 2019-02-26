// https://leetcode.com/problems/word-break/description/

class Solution {
public:
    unordered_map<int, bool> dp;
    int n;
    
    int getkey(int s, int l){
        return s * n + l;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length() + 1;
        return dfs(s, wordDict, 0, s.length());
    }
    
    bool dfs(string& s, vector<string>& wordDict, int start, int len){
        if (len == 0) return true;
        int key = getkey(start, len);
        if (dp.count(key)) return dp[key];
        bool flag = false;
        for(string& ss : wordDict){
            if (flag) break;
            else if (startswith(s, ss, start, len))
                flag = flag || dfs(s, wordDict, start + ss.length(), len - ss.length());
        }
        dp[key] = flag;
        return flag;
    }
    
    bool startswith(string& s, string& t, int idx, int len){
        if (len < t.length()) return false;
        
        for(int j = 0; j < t.length(); j++)
            if (s[idx + j] != t[j]) return false;
        return true;
    }
                                         
};
