// https://leetcode.com/problems/meeting-rooms/description/

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
    
    bool canAttendMeetings(vector<Interval>& intervals) {
        map<int, int> m;
        int counter = 0;
        for(auto i : intervals){
            m[i.start]++;
            m[i.end]--;
        }
        
        for(auto kv : m){
            counter += kv.second;
            if (counter > 1) return false;
        }
        return true;
    }
};
