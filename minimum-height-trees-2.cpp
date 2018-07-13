// https://leetcode.com/problems/minimum-height-trees/description/

#define mp(A, B) make_pair(A, B)
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef stack<int> stki;
typedef queue<int> qi;
typedef deque<int> dqi;
typedef unordered_map<int, int> mpii;
vpii steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    
    void dfs(unordered_map<int, set<int>>& adjList, int src, vi& path, vi& temp, int depth, int& maxDepth, int parent){
        temp.push_back(src);
        
        // this is a leaf
        if (depth > maxDepth){
            maxDepth = depth;
            path = temp;
        }
        for(int child : adjList[src]){
            if (child == parent) continue;
            dfs(adjList, child, path, temp, depth + 1, maxDepth, src);
        }
        
        temp.pop_back();
    }
    
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        
        unordered_map<int, set<int>> adjList;
        if (n == 1)
            return {0};
        for(pii& edge : edges){
            int u = edge.first, v = edge.second;
            adjList[v].insert(u);
            adjList[u].insert(v);
        }
        
        vi path, temp;
        int maxD = 0;
        dfs(adjList, 0, path, temp, 0, maxD, -1);
        int last = path.back();
        path.clear();
        temp.clear();
        maxD = 0;
        dfs(adjList, last, path, temp, 0, maxD, -1);
        int size = path.size();
        
        if (size % 2){
            return {path[size / 2]};
        } else {
            return {path[size / 2], path[size / 2 - 1]};
        }

    }
};
