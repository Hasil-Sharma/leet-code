// https://leetcode.com/problems/find-right-interval/description/

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
    
    struct cmp2 {
        inline bool operator() (const Interval& i1, const Interval& i2){
            return i1.start < i2.start;
        }
    };
    
    int findAnswer(vector<Interval>& intervals, int i){
        int val = intervals[i].end, low = 0, high = intervals.size() - 1, ans = -1;
        
        // find the index with start just greater than val
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            if (intervals[mid].start == val) {
                ans = mid;
                break;
            }
            else if (intervals[mid].start > val) {
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
       
        return ans;
    }
    vector<int> findRightInterval(vector<Interval>& intervals) {
        unordered_map<int, int> hashMap;
        vector<int> ans(intervals.size(), 0), mapping(intervals.size(), 0);
        
        for(int i = 0; i < intervals.size(); i++)
            hashMap[intervals[i].start] = i;
        
        sort(intervals.begin(), intervals.end(), cmp2());
        
        for(int i = 0; i < intervals.size(); i++)
            mapping[i] = hashMap[intervals[i].start];
        
        for(int i = 0; i < intervals.size(); i++){
            int j = findAnswer(intervals, i);
            ans[hashMap[intervals[i].start]] = (j != -1) ? mapping[j] : j;
        }
        
        return ans;
    }
};
