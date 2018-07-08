// https://leetcode.com/problems/friend-circles/description/


class Solution {
public:
    typedef vector<vector<int>> vvi;
    
    int findparent(vector<int>& parent, int i){
        if(parent[i] == -1)
            return i;
        return findparent(parent, parent[i]);
    }
    
    void unionparents(vector<int>& parent, int i, int j){
        int xset = findparent(parent, i);
        int yset = findparent(parent, j);
        parent[xset] = yset;
    }
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        int ans = 0;
        vector<int> parent(n, -1);
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if (M[i][j] == 1){
                    int x = findparent(parent, i);
                    int y = findparent(parent, j);
                    if (x != y)
                        unionparents(parent, x, y);
                }
            }
        }
        
        for(int i : parent)
            ans += (i == -1) ? 1 : 0;
        return ans;
    }
};
