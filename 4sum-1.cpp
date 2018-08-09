// https://leetcode.com/problems/4sum/description/

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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vvi ans;
        sort(nums.begin(), nums.end());
        int i;
        ff(i, 0, nums.size()){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            threeSum(nums, target - nums[i], i, ans);
        }
        return ans;
    }
    
    void threeSum(vi& nums, int target, int I, vvi& ans){
        int i;
        ff(i, I + 1, nums.size()){
            if (i > I + 1 && nums[i] == nums[i-1]) continue;
            twoSum(nums, target - nums[i], I, i, ans);
        }
    }
    
    void twoSum(vi& nums, int target, int i, int j, vvi& ans){
        int e = nums.size() - 1, s = j + 1;
        while(e > s) {
            int temp = nums[e] + nums[s];
            if (temp == target){
                ans.push_back({nums[i], nums[j], nums[s], nums[e]});
                while(nums[e] == nums[--e] && e > j);
                while(nums[s] == nums[++s] && s < nums.size());
            } else if (temp > target){
                while(nums[e] == nums[--e] && e > j);
            } else if (temp < target){
                while(nums[s] == nums[++s] && s < nums.size());
            }
        }
    }
};
