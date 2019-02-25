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
        int ans, s = 0, e = 0, rooms = 0;
        vector<int> start, end;
        
        for(auto interval: intervals){
            start.push_back(interval.start);
            end.push_back(interval.end);
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        ans = 0;
        
        for(int i = 0; i < intervals.size(); i++){
            if (end[e] <= start[i]){
                e++;
                ans--;
            }
            ans++;
            
            rooms = max(rooms, ans);
        }
        
        return rooms;
    }
};
