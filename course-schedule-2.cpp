// https://leetcode.com/problems/course-schedule/description/
 class Solution {
public:
    typedef pair<int, int> pii;
    typedef vector<int> vi;
    typedef vector<vector<int>> vvi;
    typedef vector<pair<int, int>> vpii;
    typedef vector<bool> vb;
    typedef vector<vector<bool>> vvb;
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        vi visited(numCourses, 0);
        vvi adjList(numCourses, vector<int>());
        
        for(pii edge : prerequisites)
            adjList[edge.first].push_back(edge.second);
        
        for(int i = 0 ; i < numCourses; i++)
            if (visited[i] == 0)
                if(!dfs(adjList, visited, i)) return false;
        
        return true;
    }
    
    bool dfs(vvi& adjList, vi& visited, int src){
        if(visited[src] != 0) 
            return visited[src] == 1;
        
        visited[src] = 2;
        
        for(int child : adjList[src])
            if (!dfs(adjList, visited, child)) return false;
        
        visited[src] = 1;
        
        return true;
    }
};
