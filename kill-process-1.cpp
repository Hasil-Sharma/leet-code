// https://leetcode.com/problems/kill-process/

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

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        umpiv adjList;
        stack<int> stk;
        vi ans;
        
        for(int i = 0; i < ppid.size(); i++)
            adjList[ppid[i]].push_back(pid[i]);
        
        stk.push(kill);
        
        while(!stk.empty()){
            int kill = stk.top();
            stk.pop();
            ans.push_back(kill);
            for(auto c : adjList[kill])
                stk.push(c);
        }
        
        return ans;
        
    }
};
