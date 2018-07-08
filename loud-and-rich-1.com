// https://leetcode.com/problems/loud-and-rich/description/

class Solution {
public:
    typedef vector<vector<int>> vvi;
    typedef vector<int> vi;
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int N = quiet.size();
        vi answer(N, -1);
        vvi adjMatrix(N, vector<int>());
        
        for(vi edge : richer)
            adjMatrix[edge[1]].push_back(edge[0]);
            
        for(int p = 0; p < N; p++)
            if (answer[p] == -1)
                dfs(p, adjMatrix, quiet, answer);
        
        return answer;
    }
    
    void dfs(int n, vvi& adjMatrix, vi& quiet, vi& answer){
        answer[n] = n;
        for(int child : adjMatrix[n]){
            if (answer[child] == -1)
                dfs(child, adjMatrix, quiet, answer);
            answer[n] = quiet[answer[child]] < quiet[answer[n]] ? answer[child] : answer[n];
        }
    }
};
