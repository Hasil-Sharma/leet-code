// https://leetcode.com/problems/open-the-lock/description/

class Solution {
public:
    unordered_map<string, bool> dp;
    string start = "0000";
    
    int openLock(vector<string>& deadends, string target) {
        for(string deadend : deadends)
            dp[deadend] = true;
        
        int ans = INT_MAX;
        
        queue<pair<string, int>> q;
        
        if (!dp.count(target))
            q.push({target, 0});
        
        while(!q.empty() && ans == INT_MAX){
            auto p = q.front();
            q.pop();
            target = p.first;
            if (dp.count(target)){
                continue;
            } else if (target == start){
                ans = p.second;
            } else {
                dp[target] = true;
                for(int i = 0; i < 4; i++){
                    for(int j = -1; j < 2; j+=2){
                        char t = target[i];
                        char c = target[i] + j;
                        if (c == '9' + 1) c = '0';
                        else if (c == '0' - 1) c = '9';
                        target[i] = c;
                        q.push({target, p.second + 1});
                        target[i] = t;
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
