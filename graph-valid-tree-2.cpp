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
        vi mask(n, -1);
        bool flag = bfs(adjList, mask, 0, -1);
        for(auto m : mask)
            flag = flag && (m > -1);
        return flag;
    }
    
    bool bfs(unordered_map<int, vi> adjList, vi& mask, int src, int parent){
        qi q;
        q.push(src);
        mask[src] = src;
        while(!q.empty()){
            src = q.front();
            q.pop();
            for(int child : adjList[src]){
                if (child == mask[src]) continue;
                if (mask[child] != -1) return false;
                mask[child] = src;
                q.push(child);
            }
        }
        return true;
    }
};
