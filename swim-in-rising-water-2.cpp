// https://leetcode.com/problems/swim-in-rising-water/description/ 

class Solution {
public:
    
    struct T {
        int t, x, y;
        T(int a, int b, int c) : t (a), x (b), y (c){}
        bool operator< (const T &d) const {return t > d.t;}
    };
    
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size(), ans = 0;
        priority_queue<T> pq;
        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        pq.push(T(grid[0][0], 0, 0));
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        visited[0][0] = true;
        
        while(true){
            auto p = pq.top();
            // lowest water level to move forward
            ans = max(ans, p.t);
            pq.pop();
            if (p.x == N - 1 && p.y == N - 1)
                return ans;
            for(auto& d: dir){
                int i = p.x + d[0], j = p.y + d[1];
                if (i >= 0 && j >= 0 && i < N && j < N && !visited[i][j]){
                    visited[i][j] = true;
                    pq.push(T(grid[i][j], i, j));
                }
            }
            
        }
    }
};
