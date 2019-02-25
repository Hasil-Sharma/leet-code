// https://leetcode.com/problems/task-scheduler/

class Solution {
public:
    
    int leastInterval(vector<char>& tasks, int n) {
        int max = 0, maxCount = 0;
        unordered_map<char, int> A;
        
        for(char task: tasks){
            A[task - 'A']++;
            if (A[task - 'A'] == max){
                maxCount++;
            } else if (max < A[task -'A']){
                max = A[task - 'A'];
                maxCount = 1;
            }
        }
        
        int gaps = max - 1;
        int slots_per_gap = n - (maxCount - 1);
        int total_idles = gaps * slots_per_gap;
        int available_tasks = tasks.size() - max * maxCount;
        int idles = total_idles - available_tasks;
        
        return tasks.size() + (idles > 0) * (idles);
    }
};
