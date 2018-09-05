// https://leetcode.com/problems/task-scheduler/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counts(26, 0);
        int maxCount = 0, points = 0;
        
        for(char t : tasks){
            int c = ++counts[t - 'A'];
            if (c > maxCount){
                points = 1;
                maxCount = c;
            } else if (c == maxCount)
                points++;
        }
        int slots = maxCount - 1;
        int emptyBuckets = slots * (n - (points - 1));
        int remainingTasks = tasks.size() - maxCount*points;
        int idle = max(0, emptyBuckets - remainingTasks);
        return tasks.size() + idle;
    }
};
