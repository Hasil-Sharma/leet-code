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
          return i1.start != i2.start ? i1.start < i2.start :  i1.end < i2.end;
      }
    };
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        sort(intervals.begin(), intervals.end(), cmp());
        
        for(int i = 0; i < intervals.size(); i++){
            if (i > 0 && ans.back().end >= intervals[i].start)
                ans.back().end = max(ans.back().end, intervals[i].end);
            else
                ans.push_back(intervals[i]);
        }
        
        return ans;
    }
};
