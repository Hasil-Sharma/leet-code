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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vvi ans;
        ss(nums);
        if (nums.size()) gen_perm(ans, nums, 0);
        return ans;
    }

    void gen_perm(vvi& ans, vi& nums, int idx){
        if (idx == nums.size()) ans.push_back(nums);
        unordered_set<int> seen;
        for(int i = idx; i < nums.size(); i++){
            if(seen.count(nums[i]))
                continue;

            seen.insert(nums[i]);
            swap(nums[idx], nums[i]);
            gen_perm(ans, nums, idx+1);
            swap(nums[idx], nums[i]);
        }
    }
};
