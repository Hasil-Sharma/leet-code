// https://leetcode.com/problems/keys-and-rooms/description/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int N = rooms.size(), curr, counter = 0;
        vector<bool> visited(N, false);
        queue<int> stk;
        stk.push(0);
        
        while(!stk.empty()){
            curr = stk.front();
            stk.pop();
            if(visited[curr])
                continue;
            counter++;
            visited[curr] = true;
            for(auto room : rooms[curr]){
                stk.push(room);
            }
        }
        
        return counter == N;
    }
};
