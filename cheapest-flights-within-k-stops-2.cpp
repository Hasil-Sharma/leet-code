// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

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
typedef unordered_map<int, int> mpii;
vpii steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // find all the paths from src to dst
        // - prune the paths which are becoming more than K
        
        int ans = INT_MAX, numEdge, cost;
        vector<vpii> adjList(n, vpii());
        vi dist(n, INT_MAX);
        queue<pair<int, pii>> q;
        for(vi& flight: flights)
            adjList[flight[0]].push_back(mp(flight[1], flight[2]));
        
        q.push(mp(src, mp(0, 0)));
        // node, cost to reach, edges in path
        while(!q.empty()){
            auto front = q.front();
            src = front.first;
            cost = front.second.first;
            numEdge = front.second.second; 
            q.pop();
            
            // have to use equal as it can come from less number of paths
            // if current cost to reach path is more than the previous cost
            if (cost > dist[src] || numEdge - 1 > K) continue;
            dist[dst] = cost;
            // if it were greater previous condition would have taken care of this
            if (src != dst) {
                for(auto child : adjList[src])
                    q.push(mp(child.first, mp(cost + child.second, numEdge + 1)));
            }
        }
                
        return dist[dst] != INT_MAX ? dist[dst] : -1;
        
    }
};
