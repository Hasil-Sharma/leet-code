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
        map<int, int> tree;
        for(auto interval : intervals){
            int s = interval.start, e = interval.end;
            // and end time after this start time
            auto itr = tree.lower_bound(s);
            
            while(itr != tree.end() && itr->second <= e){
                // possible to merge
                s = min(s, itr->second);
                e = max(e, itr->first);
                itr = tree.erase(itr);
            }
            tree[e] = s;
        }
        
        vector<Interval> vec;
        for(auto itr : tree){
            vec.push_back(Interval(itr.second, itr.first));
        }
        return vec;
    }
};
