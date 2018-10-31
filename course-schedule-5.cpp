// https://leetcode.com/problems/course-schedule/description/

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
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vi indegree(numCourses, 0);
        umpiv adjList;
        for(auto e : prerequisites){
            adjList[e.second].push_back(e.first);
            indegree[e.first]++;
        }
        int n = numCourses;
        while(numCourses--){
            int i = -1;
            for(int j = 0;j < n; j++)
                if (indegree[j] == 0){
                    i = j;
                    break;
                }
            
            if (i == -1) return false;
            indegree[i] = -1;
            for(int nn : adjList[i])
                indegree[nn]--;
        }
        
        return true;
    }
};
