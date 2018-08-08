// https://leetcode.com/problems/course-schedule-ii/description/

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
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vi ans;
        umpiv adjList;
        for(pii& preq : prerequisites)
            adjList[preq.second].push_back(preq.first);
        vi color(numCourses, -1);
        int i;
        ff(i, 0, numCourses){
            if (color[i] == -1 && !dfs(adjList, color, i, ans)){
                ans.clear();
                return ans;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    bool dfs(umpiv& adjList, vi& color, int s, vi& ans){
        if (color[s] != -1) return color[s] == 1;
        color[s] = 2;
        for(int c : adjList[s]){
            if (color[c] == 2 || !dfs(adjList, color, c, ans))
                return false;
        }
        ans.push_back(s);
        return color[s] = 1;
    }
};
