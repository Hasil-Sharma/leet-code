// https://leetcode.com/problems/min-cost-climbing-stairs/description/

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
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vi ans(n + 1, 0);
        for(int i = 2; i <= n; i++)
            ans[i] = min(ans[i - 1] + cost[i - 1], ans[i - 2] + cost[i - 2]);
        
        return ans[n];
    }
};
