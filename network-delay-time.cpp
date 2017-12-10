//https://leetcode.com/problems/network-delay-time/description
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> distance(N+1, INT_MAX);
        vector<vector<int>> adjList(N + 1, vector<int>());
        vector<int> to_visit;
        vector<bool> visited(N + 1, false);
        map<pair<int, int>, int> weights;
        int ans = INT_MIN, visiting = N;
        
        for(auto edge: times){
            weights[{edge[0], edge[1]}] = edge[2];
            adjList[edge[0]].push_back(edge[1]);
        }
        
        distance[K] = 0;
        
        for(int i = 1; i <= N; i++)
            to_visit.push_back(i);
        
        while(visiting >= 0){
            
            // finding the node to visit next;
            int src, temp_weight = INT_MAX;
            for(int node: to_visit){
                if (distance[node] < temp_weight && !visited[node]){
                    src = node;
                    temp_weight = distance[node];
                }
            }
            visited[src] = true;
            visiting--;
            for(int dest : adjList[src]){
                distance[dest] = min(distance[dest], distance[src] + weights[{src, dest}]);
            }
        }
        
        for(int i = 1; i <= N; i++){
            // cout << i << " " << distance[i] << endl;
            if (distance[i] == INT_MAX)
                return -1;
            ans = max(distance[i], ans);
        }
        
        return ans;
    }
};

