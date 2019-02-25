// https://leetcode.com/problems/exclusive-time-of-functions/
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans = vector<int>(n, 0);
        
        stack<pair<int, int>> stk;
        string s1, s2, s3;
        int id, time;
        
        for(auto log : logs){
            stringstream ss = stringstream(log);
            getline(ss, s1, ':');
            getline(ss, s2, ':');
            getline(ss, s3, ':');
            id = stoi(s1);
            time = stoi(s3);
            
            if (s2 == "start"){
                stk.push({id, time});
            } else {
                int time_added = time - stk.top().second + 1;
                ans[id] += time_added;
                stk.pop();
                if (!stk.empty()){
                    ans[stk.top().first] -= time_added;
                }
            }
        }
        
        return ans;
    }
};
