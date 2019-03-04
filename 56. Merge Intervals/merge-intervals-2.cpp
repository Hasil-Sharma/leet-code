// https://leetcode.com/problems/merge-intervals/description/

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
    
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp());
        vector<Interval> ans;
        
        for(auto ii : intervals){
            if (!ans.size() || (ans.back().end < ii.start)) ans.push_back(ii);
            else ans.back().end = max(ans.back().end, ii.end);
        }
        
        return ans;
    }
};
