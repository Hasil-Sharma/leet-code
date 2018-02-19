// https://leetcode.com/problems/course-schedule/description/

class Solution {
public:
    bool detectCycle(int v, vector<list<int>>& adjList, vector<bool>& visited, vector<bool>& inStack){
        if (!visited[v]){
            visited[v] = true;
            
            inStack[v] = true;
            for(int child: adjList[v]){
                // if child is in stack return true
                if (inStack[child] == true || detectCycle(child, adjList, visited, inStack)){
                    return true;
                }
            }
            inStack[v] = false;
        }
        return false;
    }
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        stack<int> stk;
        bool flag = false;
        vector<list<int>> adjList(numCourses, list<int>());
        vector<bool> visited(numCourses, false);
        vector<bool> inStack(numCourses, false);
        
        for(auto p: prerequisites){
            adjList[p.first].push_back(p.second);
        }
        
        for(int v = 0; v < numCourses && !flag; v++){
            flag = flag || detectCycle(v, adjList, visited, inStack);
        }
        return !flag;
    }
};
