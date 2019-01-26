// https://leetcode.com/problems/meeting-rooms-ii/description/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;
        
        sort(intervals.begin(), intervals.end(), 
            [](Interval i1, Interval i2){
                return i1.start < i2.start;
            });
        
        for(auto interval : intervals){
            while (pq.size() && pq.top() <= interval.start)
                pq.pop();
            pq.push(interval.end);
            ans = max(ans, int(pq.size()));
        }
        
        return ans;
    }
};
