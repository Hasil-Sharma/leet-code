// https://leetcode.com/problems/course-schedule-ii/description/

class Solution {
public:
    #define mp(A, B) make_pair(A, B)
    typedef pair<int, int> pii;
    typedef vector<int> vi;
    typedef vector<vector<int>> vvi;
    typedef vector<pair<int, int>> vpii;
    typedef vector<bool> vb;
    typedef vector<vector<bool>> vvb;
    typedef vector<string> vs;
    typedef vector<vector<string>> vvs;
    typedef stack<int> stki;
    typedef queue<int> qi;
    typedef deque<int> dqi;
    
    vector<int> findOrder(int n, vector<pair<int, int>>& preq) {
        dqi answer;
        
        vi parent(n, -1);
        vi color(n, -1);
        vvi adjList(n, vi());
        
        for(pii& p : preq){
            adjList[p.second].push_back(p.first);
        }
        
        for(int i = 0; i < n; i++){
            if (color[i] == -1){
                if(!dfs(adjList, answer, color, i)) return {};
            }
        }
        
        return {answer.begin(), answer.end()};
    }
    
    bool dfs(vvi& adjList, dqi& answer, vi& color, int src){
        if (color[src] != -1) return color[src] == 1;
        
        color[src] = 0;
        
        for(int child : adjList[src]){
            if(!dfs(adjList, answer, color, child)) return false;
        }
        
        color[src] = 1;
        answer.push_front(src);
        return true;
    }
};
