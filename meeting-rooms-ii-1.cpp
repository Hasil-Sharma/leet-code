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
    struct cmp1{
        bool operator()(Interval& i1, Interval& i2){
            return i1.start < i2.start;
        }
    };
    
    struct cmp2 {
        bool operator()(Interval& i1, Interval& i2){
            return i1.end > i2.end;
        }
    };
    
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp1());
        priority_queue<Interval, vector<Interval>, cmp2> pq;
        
        int ans = 0;
        
        for(auto i : intervals){
            if (!pq.empty() && pq.top().end <= i.start)
                pq.pop();
            pq.push(i);
            if (pq.size() > ans)
            ans = pq.size();
        }
        return ans;
    }
};
