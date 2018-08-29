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
    struct cmp {
        bool operator()(Interval& i1, Interval& i2){
            return i1.start != i2.start ? i1.start < i2.start : i1.end < i2.end;
        }
    };
    
    struct cmp1 {
        bool operator()(int& i1, int& i2){
            return i1 > i2;
        }
    };
    
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp());
        priority_queue<int, vector<int>, cmp1> pq;
        int ans = 0;
        
        for(auto ii : intervals){
            if (pq.size() && pq.top() <= ii.start) {
                pq.pop();
            }
            
            pq.push(ii.end);
            ans = pq.size() > ans ? pq.size() : ans;
        }
        
        return ans;
    }
};
