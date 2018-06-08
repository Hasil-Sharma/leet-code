// https://leetcode.com/problems/course-schedule-ii/description/

class Solution {
public:
    int white = 0, gray = 1, black = 2;
    
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> visited(numCourses, 0);
        unordered_map<int, vector<int>> adjList;
        stack<int> stk;
        vector<int> ans;
        bool flag = true;
        
        for(int i = 0; i < numCourses; i++)
            adjList[i];
        
        // for example to take course 0 
        // you have to first take course 1, 
        // which is expressed as a pair: [0,1]
        
        for(auto& p: prerequisites)
            adjList[p.second].push_back(p.first);
        
        for(int i = 0; i < numCourses && flag; i++){
            if (visited[i] != 0)
                continue;
            flag = dfs(i, visited, adjList, ans);
            ans.insert(ans.begin(), i);
        }
        
        return flag ? ans : vector<int>();
    }
    
    bool dfs (int i, vector<int>& visited, unordered_map<int, vector<int>> & adjList, vector<int>& ans){
        visited[i] = 1;
        bool flag = true;
        for(int &child : adjList[i]){
            if (visited[child] == 1) return false;
            else if (visited[child] == black)
                continue;
            flag = dfs(child, visited, adjList, ans);
            if (!flag) break;
            ans.insert(ans.begin(), child);
        }
        visited[i] = 2;
        return flag;
    }
};
