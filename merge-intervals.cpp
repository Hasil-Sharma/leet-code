// https://leetcode.com/problems/merge-intervals/discuss/
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool customCmp (Interval& i1, Interval& i2) { return i1.start < i2.start; }

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        if (intervals.size() == 0) return ans;
        sort(intervals.begin(), intervals.end(), customCmp);
        ans.push_back(intervals[0]);
        
        for(int i = 1; i < intervals.size(); i++){
            // check can be merged
            if (ans.back().end >= intervals[i].start){
                // merge
                ans.back().end = max(ans.back().end, intervals[i].end);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        
        return ans;
    }
};

