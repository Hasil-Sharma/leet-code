// https://leetcode.com/problems/shortest-bridge/

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
    int shortestBridge(vector<vector<int>>& A) {
        int m = A.size(), n = m ? A[0].size() : 0, ans = 0;
        bool flag = false;
        vvb mask = vvb(m, vb(n, false));
        queue<pii> qq;
        
        for(int i = 0; i < m && !flag; i++){
            for(int j = 0; j < n && !flag; j++){
                flag = A[i][j] && dfs(A, qq, mask, i, j);
            }
        }
        
        flag = true;
        
        while(!qq.empty() && flag){
            int size = qq.size();
            
            while(size--){
                auto front = qq.front();
                qq.pop();
                int i = get<0>(front), j = get<1>(front);
                for(auto step : steps){
                    int ii = i + get<0>(step), jj = j + get<1>(step);

                    if (ii >= 0 && jj >= 0 && ii < m && jj < n && !mask[ii][jj]){
                        mask[ii][jj] = true;
                        if (A[ii][jj] == 1) flag = false;
                        else qq.push({ii, jj});
                    }
                }
            }
            
            ++ans;
        }
        
        return ans - 1;
    }
    
    bool dfs(vvi& A, queue<pii>& qq, vvb& mask, int i, int j){
        int m = A.size(), n = m ? A[0].size() : 0;
        stack<pii> stk;
       
        stk.push({i, j});
        mask[i][j] = true;
        
        while(!stk.empty()){
            auto top = stk.top();
            stk.pop();
            
            i = get<0>(top); j = get<1>(top);
            qq.push({i, j});
            
            for(auto step: steps){
                int ii = i + get<0>(step), jj = j + get<1>(step);
                if (ii >= 0 && jj >= 0 && ii < n && jj < m && A[ii][jj] && !mask[ii][jj]){
                    mask[ii][jj] = true;
                    stk.push({ii, jj});
                }
            }
        }
        
        return stk.empty();
    }
};
