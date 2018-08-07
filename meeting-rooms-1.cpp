// https://www.lintcode.com/problem/meeting-rooms/description

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    
    struct cmp {
        bool operator()(Interval& i1, Interval& i2){
            return i1.start < i2.start;
        }
    };
    bool canAttendMeetings(vector<Interval> &intervals) {
        // Write your code here
        sort(intervals.begin(), intervals.end(), cmp());
        int endTime = -1;
        for(auto i : intervals){
            if (endTime > i.start) return false;
            endTime = i.end;
        }
        return true;
    }
};
