// https://leetcode.com/problems/find-eventual-safe-states/description/

class Solution {
public:
    typedef vector<int> vi;
    typedef vector<vector<int>> vvi;
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        deque<int> answer;
        int N = graph.size();
        vector<int> visited(N, 0);
        for(int i = 0; i < N; i++){
            dfs(graph, visited, i);
        }
        
        for(int i = 0; i < N; i++)
            if (visited[i] == 2)
            answer.push_back(i);
        return {answer.begin(), answer.end()};
    }
    
    bool dfs(vvi& graph, vi& visited, int n){
        if (visited[n] != 0) return visited[n] == 2;
        visited[n] = 1;
        
        for(int child : graph[n]){
            if (!dfs(graph, visited, child)) return false;
        }
        
        visited[n] = 2;
        return true;
    }
};
