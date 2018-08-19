// https://leetcode.com/problems/insert-interval/description/

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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        bool flag = true;
        
        for(auto ii : intervals){
            if (ii.end < newInterval.start) ans.push_back(ii);
            else {
                if (flag) {
                    ans.push_back(newInterval);
                    flag = false;
                }
                if (ii.start <= ans.back().end){
                    ans.back().start = min(ans.back().start, ii.start);
                    ans.back().end = max(ans.back().end, ii.end);
                } else ans.push_back(ii);
            }
        }
        if (flag) ans.push_back(newInterval);
        return ans;
    }
};
