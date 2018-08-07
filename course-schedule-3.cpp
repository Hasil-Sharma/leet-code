// https://leetcode.com/problems/course-schedule/description/

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
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        umpiv adjList;
        for(pii& e : prerequisites)
            adjList[e.second].push_back(e.first);
        bool flag = true;
        
        vi visisted(numCourses, 0);
        int i;
        ff(i, 0, numCourses){
            if (visisted[i] == 0 && flag)
                flag = dfs(i, adjList, visisted);
        }
        return flag;
    }
    
    bool dfs(int s, umpiv& adjList, vi& visisted){
        if (visisted[s] != 0)
            return visisted[s] == 1;
        bool flag = true;
        visisted[s] = 2;
        for(int c : adjList[s]){
            if (!dfs(c, adjList, visisted))
                return false;
        }
        return visisted[s] = 1;
    }
};
