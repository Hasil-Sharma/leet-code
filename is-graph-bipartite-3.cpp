// https://leetcode.com/problems/is-graph-bipartite/description/

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

template <typename T>
void printVec(T const& t){
    for(auto e :  t)
        cout << e << ",";
    cout << endl;
}
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vi color(n, -1);
        for(int i = 0; i < n; i++){
            if (color[i] != -1) continue;
            color[i] = 0;
            if (!fillColor(graph, color, i)) return false;
        }
        return true;
    }
    
    bool fillColor(vvi& graph, vi& color, int p){
        bool flag = true;
        for(int c : graph[p]){
            if (!flag) return false;
            else if (color[c] != -1){
                if (color[c] != (!color[p])) return false;
            } else {
                color[c] = (!color[p]);
                flag = fillColor(graph, color, c);
            }
        }
        return flag;
    }
};
