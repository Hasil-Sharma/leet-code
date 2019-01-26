// https://leetcode.com/problems/meeting-rooms-ii/description/

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int ans = 0, cur = 0;
        map<int, int> mp;
        
        for(auto ii : intervals){
            mp[ii.start] += 1;
            mp[ii.end] -= 1;
        }
        
        for(auto itr : mp)
            ans = max(ans, cur += itr.second);
        
        return ans;
    }
};
