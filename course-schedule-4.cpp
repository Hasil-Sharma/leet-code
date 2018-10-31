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
        vi colors(numCourses, 0);
        umpiv adjList;
        for(auto e : prerequisites)
            adjList[e.second].push_back(e.first);
        
        for(int i = 0; i < numCourses; i++){
            if (colors[i] == 0 && !helper(i, colors, adjList))
                return false;
        }
        
        return true;
    }
    
    bool helper(int s, vi& colors, umpiv& adjList){
        if (colors[s] != 0) return colors[s] == 1;
        
        colors[s] = 2;
        
        for(int e : adjList[s]){
            if(!helper(e, colors, adjList))
                return false;
        }
        
        return colors[s] = 1;
    }
};
