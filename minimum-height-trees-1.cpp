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
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vi leaves;
        
        unordered_map<int, set<int>> adjList;
        
        for(pii& edge : edges){
            int u = edge.first, v = edge.second;
            adjList[v].insert(u);
            adjList[u].insert(v);
        }
        
        for(auto kv: adjList){
            if (kv.second.size() == 1)
                leaves.push_back(kv.first);
        }
        
        while(n > 2){
            n -= leaves.size();
            vi newleaves;
            
            for(int leaf : leaves){
                // remove the current leaf
                int node = *adjList[leaf].begin(); // there is only one node
                adjList[node].erase(leaf);  // remove the leaf from its parent
                
                if (adjList[node].size() == 1) newleaves.push_back(node);
                
            }
            leaves = newleaves;
        }
        if (leaves.size() == 0 && n == 1)
            leaves.push_back(0);
        
        return leaves;
    }
};
