// https://leetcode.com/problems/number-of-islands/description/

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
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0, m = grid.size(), n = m ? grid[0].size() : 0, i, j;
        
        ff(i, 0, m)
            ff(j, 0, n){
            if (grid[i][j] == '1'){
                ++ans;
                markVisited(grid, i, j, m, n);
            }
        }
        
        return ans;
    }
    
    void markVisited(vvc& grid, int i, int j, int m, int n){
        stack<pii> qq;
        qq.push({i, j});
        
        while(!qq.empty()){
            auto ss = qq.top();
            qq.pop();
            grid[ss.first][ss.second] = '0';
            for(auto step : steps){
                int ii = get<0>(ss) + get<0>(step), jj = get<1>(ss) + get<1>(step);
                if (ii >= 0 && jj >= 0 && ii < m && jj < n && grid[ii][jj] == '1')
                    qq.push({ii, jj});
            }
        }
    }
};
