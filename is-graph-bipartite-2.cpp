// https://leetcode.com/problems/is-graph-bipartite/submissions/1

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
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(), node, i;
        vi color(n, -1);
        qi q;
        ff(i, 0, n){
            if (color[i] != -1) continue;
            color[i] = 0;
            q.push(i);
            while(!q.empty()){
                node = q.front();
                q.pop();
                for(int c : graph[node]){
                    if (color[c] == color[node]) return false;
                    else if (color[c] == -1){
                        color[c] = (!color[node]);
                        q.push(c);
                    }
                }
            }
        }
        return true;
    }
};
