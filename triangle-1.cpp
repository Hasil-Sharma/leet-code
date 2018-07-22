// https://leetcode.com/problems/triangle/description/

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
typedef queue<pair<int, int>> qpii;
typedef unordered_map<int, int> umpii;
typedef set<int> si;
typedef unordered_set<int> usi;
vpii steps = {{1, 0}, {1,1}};

template <typename T>
void printVec(T const& t){
    for(auto e :  t)
        cout << e << ",";
    cout << endl;
}

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int h = triangle.size(), ans = INT_MAX;
        vvi dp(h + 1, vi(h + 1, 0));
        vvb mask(h + 1, vb(h + 1, false));
        
        if (h > 0)
        helper(triangle, 0, 0, dp, mask);
        
        return dp[0][0];
    }
    
    int helper(vvi& triangle, int h, int idx, vvi& dp, vvb& mask){
        if (mask[h][idx]) 
            return dp[h][idx];
        
        mask[h][idx] = true;
        dp[h][idx] = triangle[h][idx];
        
        if (h + 1 == triangle.size()) return dp[h][idx];
        else dp[h][idx] += min(helper(triangle, h + 1, idx, dp, mask), helper(triangle, h + 1, idx + 1, dp, mask));
        
        return dp[h][idx];
    }
};
