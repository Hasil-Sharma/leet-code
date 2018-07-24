// https://www.lintcode.com/problem/longest-continuous-increasing-subsequence/description

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

template <typename T>
void printVec(T const& t){
    for(auto e :  t)
        cout << e << ",";
    cout << endl;
}
class Solution {
public:
    /**
     * @param A: An array of Integer
     * @return: an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int> &A) {
        // write your code here
        int ans = 0, tans = 0, n = A.size(), i;
        
        if(n == 0) return ans;
        
        tans = 1;
        int temp = A[0];
        ff(i, 0, n){
            if (A[i] <= temp){
                ans = max(tans, ans);
                tans = 1;
            } else tans++;
            temp = A[i];
        }
        ans = max(tans, ans);
        tans = 1;
        temp = A[n-1];
        
        ffr(i, n - 1, 0){
            if (A[i] <= temp){
                ans = max(tans, ans);
                tans = 1;
            } else tans++;
            temp = A[i];
        }
        
        ans = max(tans, ans);
        return ans;
    }
};
