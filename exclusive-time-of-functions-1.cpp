// https://leetcode.com/problems/exclusive-time-of-functions/description/

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<pair<int, int>> stk;
        
        for(string log : logs){
            string id, status, time;
            stringstream ss(log);
            
            getline(ss, id, ':');
            getline(ss, status, ':');
            getline(ss, time, ':');
            
            int iid = stoi(id), ttime = stoi(time);
            if (status == "start"){
                stk.push({iid, ttime});
            } else {
                int time_added = ttime - stk.top().second + 1;
                ans[iid] += time_added;
                stk.pop();
                
                if(!stk.empty()){
                    ans[stk.top().first] -= time_added;
                }
            }
        }
        
        return ans;
    }
};
