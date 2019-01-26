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

#define mp(A, B) make_pair(A, B)
#define ff(i, m, n) for(i = m; i < n; i++)
#define ffr(i, m, n) for(i = m; i >= n; i--)
#define ss(v) sort(v.begin(), v.end())
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<pair<int, int>> vpii;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vector<string>> vvs;
typedef stack<int> stki;
typedef queue<int> qi;
typedef deque<int> dqi;
typedef queue<pair<int, int>> qpii;
typedef unordered_map<int, int> umpii;
typedef unordered_map<int, vi> umpiv;
typedef set<int> si;
typedef unordered_set<int> usi;

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vi start, end;
        
        for(auto ii: intervals){
            start.push_back(ii.start);
            end.push_back(ii.end);
        }
        
        ss(start); ss(end);
        
        int s_ptr = 0, e_ptr = 0, n = intervals.size(), ans = 0;
        
        while(s_ptr < n){
            
            if (start[s_ptr] >= end[e_ptr]){
                e_ptr++;
                ans--;
            }
            
            s_ptr++;
            ans++;
        }
        
        return ans;
        
    }
};
