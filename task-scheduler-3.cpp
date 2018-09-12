// https://leetcode.com/problems/task-scheduler/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int maxcount = 0, maxval = 0;
        vector<int> counts(26, 0);
        
        for(char t: tasks){
            counts[t - 'A']++;
            if (counts[t - 'A'] > maxval){
                maxval = counts[t - 'A'];
                maxcount = 1;
            } else if (counts[t - 'A'] == maxval)
                maxcount += 1;
        }
        
        int freeslots = (maxval - 1) * (n - maxcount + 1);
        int taskstohandle = tasks.size() - maxval * maxcount;
        int idles = max(0, freeslots - taskstohandle);
        
        return tasks.size() + idles;
    }
};
