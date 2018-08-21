// https://leetcode.com/problems/subsets-ii/description/

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
        ss(nums);
        stack<pair<vi, int>> stk;
        int n = nums.size();
        if (!n) return ans;
        
        stk.push({{}, 0});
        
        while(!stk.empty()){
            vi temp = stk.top().first;
            int idx = stk.top().second;
            stk.pop();
            ans.push_back(temp);
            for(int i = idx; i < n; i++){
                if (i > idx && nums[i] == nums[i-1])
                    continue;
                temp.push_back(nums[i]);
                stk.push({temp, i + 1});
                temp.pop_back();
            }
        }
        
        return ans;
    }
};
