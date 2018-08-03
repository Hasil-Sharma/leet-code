// https://leetcode.com/problems/subsets-ii/description/

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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vvi ans;
        sort(nums.begin(), nums.end());
        vi temp;
        helper(nums, ans, temp, 0, nums.size());
        return ans;
    }
    
    void helper(vi& nums, vvi& ans, vi& temp, int i, int n){
        ans.push_back(temp);
        if (i == n) return;
        int j;
        ff(j, i, n){
            if (j > i && nums[j] == nums[j - 1]) continue;
            temp.push_back(nums[j]);
            helper(nums, ans, temp, j + 1, n);
            temp.pop_back();
        }
    }
};
