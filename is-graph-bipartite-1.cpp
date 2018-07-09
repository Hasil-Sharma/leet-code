// https://leetcode.com/problems/is-graph-bipartite/description/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> color(N, -1);
        
        for(int i = 0; i < N; i++){
            if (color[i] == -1){
                queue<int> q;
                q.push(i);
                
                while(!q.empty()){
                    
                    int n = q.front();
                    q.pop();
                    
                    if (color[n] == -1) 
                        color[n] = 0;
                    
                    for(int child : graph[n]){
                        if (color[child] == color[n]) return false;
                        else if (color[child] == -1){
                            color[child] = (!color[n]);
                            q.push(child);
                        }
                    }
                    
                }
            }
        }
        
        return true;
    }
};
