// https://leetcode.com/problems/intersection-of-two-arrays-ii/description/

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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vi ans;
        umpii c1, c2;
        
        for(int num : nums1)
            c1[num]++;
        
        for(int num : nums2)
            c2[num]++;
        
        for(auto kv : c1){
            if (c2.count(kv.first)){
                int c = min(kv.second, c2[kv.first]);
                while(c--)
                    ans.push_back(kv.first);
            }
        }
        
        return ans;
    }
};
