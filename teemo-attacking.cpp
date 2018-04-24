// https://leetcode.com/problems/teemo-attacking/submissions/1

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int answer = (timeSeries.size() > 0) ? duration : 0, diff;
        for(int i = 1; i < timeSeries.size(); i++){
            diff = timeSeries[i] - timeSeries[i - 1];
            answer += (diff >= duration) ? duration : diff;
        }
        return answer;
    }
};
