// https://leetcode.com/problems/exclusive-time-of-functions/description/

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        int diff = 0, id, t;
        stack<pair<int, int>> stk;
        
        for(string log: logs){
            if(parse(log, id, t)) stk.push({id, t});
            else {
                int time_added = t - get<1>(stk.top()) + 1;
                ans[id] += time_added;
                stk.pop();
                if (!stk.empty())
                    ans[get<0>(stk.top())] -= time_added;
            }
        }
        
        return ans;
    }
    
    bool parse(string& log, int& id, int &t){
        bool flag = false;
        int i = 0;
        
        while(log[i] != ':')
            ++i;
        id = stoi(log.substr(0, i++));
        
        flag = log[i] == 's';
        
        i += flag ? 6 : 4;
        
        t = stoi(log.substr(i));
        
        return flag;
    }
};
