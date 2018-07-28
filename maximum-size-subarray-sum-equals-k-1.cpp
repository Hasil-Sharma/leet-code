// https://www.lintcode.com/problem/maximum-size-subarray-sum-equals-k/description

#define mp(A, B) make_pair(A, B)
#define ff(i, m, n) for(int i = m; i < n; i++)
#define ffr(i, m, n) for(int i = m; i >= n; i--)
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
     * @param nums: an array
     * @param k: a target value
     * @return: the maximum length of a subarray that sums to k
     */
    int maxSubArrayLen(vector<int> &nums, int k) {
        // Write your code here
        int rr = 0, n = nums.size(), ans = 0;
        umpii firstIdx;
        firstIdx[0] = -1; // handles the case when rr == k;
        ff(i, 0, n){
            rr += nums[i];
            if (nums[i] == k) ans = max(ans, 1);
            if (!firstIdx.count(rr)) firstIdx[rr] = i;
            if (firstIdx.count(rr - k)) ans = max(ans, i - firstIdx[rr - k]);
        }
        return ans;
    }
};
