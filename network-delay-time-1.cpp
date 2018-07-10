// https://leetcode.com/problems/network-delay-time/description/

class Solution {
public:
    typedef pair<int, int> pii;
    
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dist(N + 1, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        int ans = -1, n = 0, u , v;
        
        unordered_map<int, vector<int>> adjList;
        vector<vector<int>> adjMatrix(N + 1, vector<int>(N + 1, 0));
        
        for(vector<int> time : times){
            u = time[0]; v = time[1];
            
            if (!adjList.count(u)) adjList[u] = {v};
            else adjList[u].push_back(v);
            
            adjMatrix[u][v] = time[2];
        }
        
        pq.push(make_pair(0, K));
        dist[K] = 0;
        
        while(!pq.empty()){
            K = pq.top().second;
            pq.pop();
            
            for(int child : adjList[K]){
                if (dist[child] > dist[K] + adjMatrix[K][child]){
                    dist[child] = dist[K] + adjMatrix[K][child];
                    pq.push(make_pair(dist[child], child));
                }
            }
        }
        
        for(int i = 1; i <= N; i++){
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
        
    }
};
