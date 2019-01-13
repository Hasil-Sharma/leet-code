// https://leetcode.com/problems/product-of-array-except-self/description/

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
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), rpod = 1;
        vector<int> ans(n);
        
        ans[0] = nums[0];
        
        for(int i = 1; i < n; i++)
            ans[i] = nums[i] * ans[i-1];
        
        for(int i = n - 1; i > 0; i--){
            ans[i] = ans[i-1] * rpod;
            rpod = rpod * nums[i];
        }
        
        ans[0] = rpod;
        
        return ans;
    }
};
