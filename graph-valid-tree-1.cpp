// https://www.lintcode.com/problem/graph-valid-tree/description

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
typedef vector<vector<string>> vvs;
typedef stack<int> stki;
typedef queue<int> qi;
typedef deque<int> dqi;
typedef queue<pair<int, int>> qpii;
typedef unordered_map<int, int> umpii;
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
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
        unordered_map<int, vi> adjList;
        for(auto e : edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        vb mask(n, false);
        bool flag = dfs(adjList, mask, 0, -1);
        for(auto m : mask)
            flag = flag && m;
        return flag;
    }
    
    bool dfs(unordered_map<int, vi> adjList, vb& mask, int src, int parent){
        if (mask[src]) return false;
        bool flag = true;
        mask[src] = true;
        for(int child: adjList[src]){
            if (child == parent)
                continue;
            flag = flag && dfs(adjList, mask, child, src);
            if (!flag) break;
        }
        return flag;
    }
};
