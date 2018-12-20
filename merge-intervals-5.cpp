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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        sort(intervals.begin(), intervals.end(), cmp());
        
        for(auto ii : intervals){
            if (ans.size() && ans.back().end >= ii.start)
                ans.back().end = max(ans.back().end, ii.end);
            else ans.push_back(ii);
        }
        
        return ans;
    }
    
private:
    struct cmp{
        bool operator()(Interval& i1, Interval& i2){
            return i1.start < i2.start;
        }
    };
};
