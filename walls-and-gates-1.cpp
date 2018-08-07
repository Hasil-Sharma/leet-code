// https://www.lintcode.com/problem/walls-and-gates/description

#define mp(A, B) make_pair(A, B)
#define ff(i, m, n) for(i = m; i < n; i++)
#define ffr(i, m, n) for(i = m; i >= n; i--)
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

template <typename T>
void printVec(T const& t){
    for(auto e :  t)
        cout << e << ",";
    cout << endl;
}
class Solution {
public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    void wallsAndGates(vector<vector<int>> &rooms) {
        // write your code here
        int m = rooms.size(), n = m ? rooms[0].size() : 0, i = 0, j = 0;
        if (!m) return;
        
        ff(i, 0, m)
        ff(j, 0, n)
        if (rooms[i][j] == 0)
        bfs(rooms, i, j, m, n);
    }
    
    void bfs(vvi& rooms, int i, int j, int m, int n){
        queue<pair<pii, int>> q;
        int d;
        q.push({{i, j}, 0});
        while(!q.empty()){
            auto front = q.front(); 
            i = front.first.first; j = front.first.second; d = front.second;
            q.pop();
            if (rooms[i][j] < d){
                continue;
            }
            rooms[i][j] = d;
            for(auto step: steps){
                int ii = i + step.first, jj = j + step.second;
                if (ii >= 0 && jj >= 0 && ii < m && jj < n && rooms[ii][jj] > d + 1)
                q.push({{ii, jj}, d + 1});
            }
            
        }
    }
};
