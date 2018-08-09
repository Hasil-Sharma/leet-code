// https://leetcode.com/problems/intersection-of-two-arrays-ii/description/

#define mp(A, B) make_pair(A, B)
#define ff(i, m, n) for(i = m; i < n; i++)
#define ffr(i, m, n) for(i = m; i >= n; i--)
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

template <typename T>
void printVec(T const& t){
    for(auto e :  t)
        cout << e << ",";
    cout << endl;
}
class Solution {
public:
    void genMap(umpii& m, vi& nn){
        for(int n : nn)
            m[n]++;
    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vi ans;
        umpii m1, m2;
        genMap(m1, nums1);
        genMap(m2, nums2);
        
        for(auto kv: m1){
            if (m2.count(kv.first)){
                int i;
                ff(i, 0, min(kv.second, m2[kv.first]))
                    ans.push_back(kv.first);
            }
        }
        return ans;
    }
};
