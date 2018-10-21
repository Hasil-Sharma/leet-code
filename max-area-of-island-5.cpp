// https://leetcode.com/problems/max-area-of-island/description/

#define mp(A, B) make_pair(A, B)
#define ff(i, m, n) for(i = m; i < n; i++)
#define ffr(i, m, n) for(i = m; i >= n; i--)
#define ss(v) sort(v.begin(), v.end())
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<pair<int, int>> vpii;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vector<string>> vvs;
typedef stack<int> stki;
typedef queue<int> qi;
typedef deque<int> dqi;
typedef queue<pair<int, int>> qpii;
typedef unordered_map<int, int> umpii;
typedef unordered_map<int, vi> umpiv;
typedef set<int> si;
typedef unordered_set<int> usi;
vpii steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = m ? grid[0].size() : 0;
        if (!m || !n) return ans;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (grid[i][j] == 1)
                    ans = max(ans, mark(grid, i, j, m, n));
            }
        }
        
        return ans;
    }
    
    int mark(vvi grid, int i, int j, int m, int n){
        stack<pii> toVisit;
        toVisit.push({i, j});
        grid[i][j] = 0;
        int ans = 1;
        while(!toVisit.empty()){
            i = toVisit.top().first;
            j = toVisit.top().second;
            toVisit.pop();
            for(auto step : steps){
                int ii = i + step.first, jj = j + step.second;
                if (ii >= 0 && jj >= 0 && ii < m && jj < n && grid[ii][jj]){
                    toVisit.push({ii, jj});
                    grid[ii][jj] = 0;
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
