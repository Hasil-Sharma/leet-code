// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

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
    int findKthLargest(vector<int>& nums, int k) {
        int p = quickSelect(nums, k, 0, nums.size() - 1);
        return nums[p];
    }
    
    int quickSelect(vi& nums, int k, int p, int r){
        int e = (rand() % (r - p + 1))+ p;
        swap(nums[r], nums[e]);
        int key = nums[r], i = p - 1;
        
        for(int j = p; j < r; j++){
            if (nums[j] <= key){
                i++;
                swap(nums[i], nums[j]);
            }
        }
        
        swap(nums[i+1], nums[r]);
        ++i;
        int n = nums.size();
        if (i == n - k) return i;
        else if (i < n - k) return quickSelect(nums, k, i + 1, r);
        else return quickSelect(nums, k, p, i - 1);
    }
};
