// https://leetcode.com/problems/subsets/description/

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

template <typename T>
void printVec(T const& t){
    for(auto e :  t)
        cout << e << ",";
    cout << endl;
}
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vi temp;
        vvi ans;
        if (nums.size())
        helper(nums, ans, temp, 0);
        return ans;
    }
    
    void helper(vi& nums, vvi& ans, vi& temp, int idx){
        ans.push_back(temp);
        if (idx == nums.size())
            return;
        
        for(int i = idx; i < nums.size(); i++){
            temp.push_back(nums[i]);
            helper(nums, ans, temp, i + 1);
            temp.pop_back();
        }
        
        return;
    }
    
  
};
