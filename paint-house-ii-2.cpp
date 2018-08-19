// https://leetcode.com/problems/paint-house-ii/description/

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), k = n ? costs[0].size() : 0, ans = INT_MAX;
        if (n == 0) return 0;
        
        vector<int> prev(k + 1, 0);
        
        for(int i = 1; i <= k; i++){
            prev[i] = costs[0][i-1];
        }
        
        for(int i = 2; i <= n; i++){
            vector<int> curr(k + 1, INT_MAX);
            for(int j = 1; j <= k; j++){
                for(int a = 1; a <= k; a++){
                    if (a == j) continue;
                    curr[j] = min(prev[a] + costs[i-1][j-1], curr[j]);
                }
            }
            prev = curr;
        }
        
        for(int i = 1; i <= k; i++)
            ans = min(ans, prev[i]);
        return ans;
    }
};
