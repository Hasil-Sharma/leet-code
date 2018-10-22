// https://leetcode.com/problems/the-skyline-problem/description/

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
vpii steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        return buildings.size() ? findSkyline(buildings, 0, buildings.size() - 1) : vpii();
    }
    
    vpii findSkyline(vvi& buildings, int start, int end){
        if (start == end) {
            vpii ans;
            ans.push_back({buildings[start][0], buildings[start][2]});
            ans.push_back({buildings[start][1], 0});
            return ans;
        }
        
        int m = start + (end - start) / 2;
        
        vpii left = findSkyline(buildings, start, m);
        vpii right = findSkyline(buildings, m+1, end);
        
        return mergeSkyline(left, right);
    }
    
    vpii mergeSkyline(vpii& left, vpii& right){
        int l = left.size(), r = right.size();
        
        int h1 = 0, h2 = 0, h = 0, i = 0, j = 0, x = 0;
        vpii ans;
        
        while(i < l && j < r){
            if (left[i].first > right[j].first){
                x = right[j].first;
                h2 = right[j++].second;
                h = max(h1, h2);
            } else if (left[i].first < right[j].first){
                x = left[i].first;
                h1 = left[i++].second;
                h = max(h1, h2);
            } else {
                x = left[i].first;
                h1 = left[i++].second;
                h2 = right[j++].second;
                h = max(h1, h2);
            }
            
            if (ans.size() == 0 || (ans.back().second != h))
                ans.push_back({x, h});
        }
        
        while(i < l)
            ans.push_back(left[i++]);
        
        while(j < r)
            ans.push_back(right[j++]);
        
        return ans;
    }
};
