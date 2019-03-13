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
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int>> qq;
        int m = rooms.size(), n = m ? rooms[0].size() : 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (rooms[i][j] == 0)
                    qq.push({i, j});
            }
        }
        
        bfs(qq, rooms, m, n);
    }
    
    
    void bfs(queue<pair<int, int>>& qq, vvi& rooms, int m, int n){
        
        while(!qq.empty()){
            auto front = qq.front();
            int i = get<0>(front), j = get<1>(front);
            qq.pop();
            
            for(auto step : steps){
                int ii = i + step.first, jj = j + step.second;
                
                if (ii >= 0 && jj >= 0 && ii < m && jj < n && rooms[ii][jj] > 0 && rooms[ii][jj] > rooms[i][j] + 1){
                    rooms[ii][jj] = rooms[i][j] + 1;
                    qq.push({ii, jj});
                }
            }
        }
    }
};
