// https://leetcode.com/problems/friend-circles/description/


class Solution {
public:
    typedef vector<vector<int>> vvi;
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            dfs(M, i, ans, true);
        }
        return ans;
    }
    
    void dfs(vvi& M, int i, int& ans, bool flag){
        for(int j = 0; j < M.size(); j++){
            if (M[i][j] == 1){
                M[i][j] = 0;
                if (j != i) dfs(M, j, ans, false);
                else if (flag && i == j) ans++;
            }
        }
    }
};
