// https://leetcode.com/problems/bus-routes/description/

#define mp(A, B) make_pair(A, B)
#define ff(i, m, n) for(i = m; i < n; i++)
#define ffr(i, m, n) for(i = m; i >= n; i--)
#define ss(v) sort(v.begin(), v.end())
#define N 1000000
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
    
    bool hasCommon(vi& r1, vi& r2){
        int i = 0, j = 0;
        
        while(i < r1.size() && j < r2.size()){
            if (r1[i] == r2[j]) return true;
            else if (r1[i] > r2[j]) j++;
            else i++;
        }
        
        return false;
    }
    
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        umpiv adjList;
        usi visited, stopRoute;
        qpii qq;
        int n = routes.size();
        if (S == T) return 0;
        
        // n - size of routes
        // m - average size of each route
        
        // O(nlogm + nm)
        for(int i = 0; i < n; i++){
            ss(routes[i]);
            for(auto x : routes[i]){
                if (x == S) qq.push({i, 1});
                else if (x == T) stopRoute.insert(i);
            }
        }
        
        // O(n*n*m)
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if (hasCommon(routes[i], routes[j])){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        
        // O(n + n*n) - V = n, E = n*n
        while(!qq.empty()){
            auto front = qq.front();
            qq.pop();
            if (stopRoute.count(get<0>(front))) return get<1>(front);
            visited.insert(get<0>(front));
            
            for(int ii : adjList[get<0>(front)]){
                if (!visited.count(ii))
                    qq.push({ii, get<1>(front) + 1});
            }
        }
        
        return -1;
    }
};
