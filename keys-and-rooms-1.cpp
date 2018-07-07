// https://leetcode.com/problems/keys-and-rooms/description/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int N = rooms.size(), curr, counter = 0;
        vector<bool> visited(N, false);
        dfs(rooms, visited, counter, 0);
        return counter == N;
    }
    
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int& counter, int start){
        if (visited[start]) return;
        visited[start] =true;
        counter++;
        for(auto key : rooms[start])
            dfs(rooms, visited, counter, key);
    }
};
