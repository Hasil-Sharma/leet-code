// https://leetcode.com/problems/task-scheduler/description/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // adding events to a priority queue
        unordered_map<char, int> tasks_count;
        priority_queue<int> pq;
        int cycle = n + 1, answer = 0, time;
        
        for(char t : tasks)
            tasks_count[t] += 1;
        
        for(auto t : tasks_count)
            pq.push(t.second);
        
        while(!pq.empty()){
            vector<int> temp;
            time = 0;
            
            for(int i = 0; i < cycle && !pq.empty(); i++){
                temp.push_back(pq.top());
                pq.pop();
                time++;
            }
            
            for(auto t : temp){
                if(--t)
                    pq.push(t);
            }
            
            answer += !pq.empty() ? cycle : time;
        }
        
        return answer;
    }
};
