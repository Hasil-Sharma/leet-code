// https://leetcode.com/problems/valid-triangle-number/description/

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
    int triangleNumber(vector<int>& nums) {
        ss(nums);
        int ans = 0;
        int i,j,k;
        ff(i, 0, nums.size()){
            ff(j, i + 1, nums.size()){
                k = find(nums, nums[i] + nums[j], j+1);
                if (k != -1)
                ans += k - j;
            }
        }
        return ans;
    }
    
    int find(vi& nums, int target, int start){
        
        int s = start, e = nums.size() - 1, ans = -1;
        while(s <= e){
            int m = s + (e - s) / 2;
            if (nums[m] >= target) e = m - 1;
            else {
                ans = m;
                s = m + 1;
            }
        }
        return ans;
    }
};
