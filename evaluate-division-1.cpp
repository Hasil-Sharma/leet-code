// https://leetcode.com/problems/evaluate-division/

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> ans;
        unordered_map<string, vector<pair<string, double>>> adjList;
        int n = equations.size();
        for(int i = 0; i < n; i++){
            string f = get<0>(equations[i]), s = get<1>(equations[i]);
            adjList[f].push_back({s, values[i]});
            adjList[s].push_back({f, 1.0/values[i]});
        }
        
        for(pair<string, string> query : queries){
            string start = get<0>(query), end = get<1>(query);
            if (!adjList.count(start) || !adjList.count(end)) ans.push_back(-1);
            else ans.push_back(dfs(start, end, adjList));
        }
        
        return ans;
    }
    
    double dfs(string node, string dest, unordered_map<string, vector<pair<string, double>>>& adjList){
        stack<pair<string, double>> stk;
        double wt;
        unordered_set<string> visit;
        stk.push({node, 1.0});
        
        while(!stk.empty()){
            node = get<0>(stk.top());
            wt = get<1>(stk.top());
            stk.pop();
            if (node == dest) return wt;
            visit.insert(node);
            for(auto child : adjList[node]){
                auto nn = get<0>(child);
                auto ww = get<1>(child);
                
                if (visit.count(nn)) continue;
                stk.push({nn, ww*wt});
            }
        }
        
        return -1;
    }
};
