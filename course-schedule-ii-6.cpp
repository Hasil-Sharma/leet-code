// https://leetcode.com/problems/course-schedule-ii/description/

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
    vector<int> findOrder(int n, vector<pair<int, int>>& prerequisites) {
        vi ans;
        umpiv adjList;
        vi indegree(n, 0);
        
        for(pii &edge : prerequisites) {
            adjList[edge.second].push_back(edge.first);
            indegree[edge.first]++;
        }
        int k = 0;
        while(ans.size() != n){
            int j;
            ff(j, 0, n)
                if (indegree[j] == 0) {
                    ans.push_back(j);
                    indegree[j]--;
                }
            if (ans.size() == k) return {};
            int size = ans.size();
            while(k < size){
                for(auto c : adjList[ans[k++]]){
                    indegree[c]--;
                }
            }
        }
        return ans;
    }
};
