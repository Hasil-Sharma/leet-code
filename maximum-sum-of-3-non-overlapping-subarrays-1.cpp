// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/description/

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
    
    void getSlidingWindowSum(vi& nums, vi& W, int K){
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if (i >= K - 1) {
                W.push_back(sum);
                sum -= nums[i - K + 1];   
            }
        }
    }
    
    void fillLeft(vi& W, vi& v, int n){
        int best = 0;
        
        for(int i = 0; i < n; i++){
            if (W[i] > W[best]) best = i;
            v[i] = best;
        }
    }
    
    void fillRight(vi& W, vi& v, int n){
        int best = n - 1;
        
        for(int i = n - 1; i >= 0; i--){
            if (W[i] >= W[best]) best = i;
            v[i] = best;
        }
    }
    
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int K) {
        vi W;
        
        getSlidingWindowSum(nums, W, K);
        int n = W.size();
        vi left(n), right(n);
        
        fillLeft(W, left, n); 
        fillRight(W, right, n);
        
        vi ans = {-1, -1, -1};
        int i, k;
        for(int j = K; j < n - K; j++){
            i = left[j - K], k = right[j + K];
            if (ans[0] == -1 || W[i] + W[j] + W[k] > W[ans[0]] + W[ans[1]] + W[ans[2]])
                ans = {i, j, k};
        }
        
        return ans;
    }
};
