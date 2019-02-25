// https://leetcode.com/problems/subsets-ii/

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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vvi ans;
        vi temp;
        ss(nums);
        helper(nums, temp, ans, 0);
        return ans;
    }
    
    void helper(vi& nums, vi& temp, vvi& ans, int idx){
        ans.push_back(temp);
        
        for(int i = idx; i < nums.size(); i++){
            if (i > idx && nums[i] == nums[i - 1]) continue;
            temp.push_back(nums[i]);
            helper(nums, temp, ans, i + 1);
            temp.pop_back();
        }
    }
};
