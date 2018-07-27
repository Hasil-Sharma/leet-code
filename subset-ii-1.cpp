// https://www.lintcode.com/problem/subsets-ii/description

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
    /**
     * @param nums: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        // write your code here
        vvi ans;
        vi temp;
        sort(nums.begin(), nums.end());
        dfs(nums, temp, ans, 0);
        return ans;
    }
    
    void dfs(vi& nums, vi& temp, vvi& ans, int start){
        ans.push_back(temp);
        int i = start;
        while(i < nums.size()){
            if (i > start && nums[i-1] == nums[i]){
                i++;
                continue;
            }
            temp.push_back(nums[i]);
            dfs(nums, temp, ans, i + 1);
            i++;
            temp.pop_back();
        }
    }
};
