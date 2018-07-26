// https://www.lintcode.com/problem/3sum/description

#define mp(A, B) make_pair(A, B)
#define ff(i, m, n) for(i = m; i < n; i++)
#define ffr(i, m, n) for(i = m; i >= n; i--)
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
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
class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @return: Find all unique triplets in the array which gives the sum of zero.
     */
    int find(vector<int>& nums, int key, int start){
        auto itr = lower_bound(nums.begin() + start, nums.end(), key);
        if (itr == nums.end() || *itr != key) return -1;
        return itr - nums.begin();
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vvi ans;
        int n = nums.size();
        if (n == 0) return ans;
        
        sort(nums.begin(), nums.end());
        
        int i, j, k;
        
        ff(i, 0, n){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            ff(j, i + 1, n){
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                int t = nums[i] + nums[j];
                k = find(nums, -t, j + 1);
                if (k == -1) continue;
                ans.push_back({nums[i], nums[j], nums[k]});
            }
        }
        
        return ans;
    }
};
