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
        int ans1 = 0, tans1 = 0, ans2 = 0, tans2 = 0, n = A.size();
        
        if(n == 0) return ans1;
        
        tans1 = tans2 = 1;
        int temp1 = A[0], temp2 = A[n-1];
        
        for(int i = 0, j = n - 1; i < n && j >= 0; i++, j--){
            if (A[i] <= temp1){
                ans1 = max(tans1, ans1);
                tans1 = 1;
            } else tans1++;
            
            if (A[j] <= temp2){
                ans2 = max(tans2, ans2);
                tans2 = 1;
            } else tans2++;
            
            temp1 = A[i];
            temp2 = A[j];
        }
        
        ans1 = max(tans1, ans1);
        ans2 = max(tans2, ans2);
        
        return max(ans1, ans2);
    }
};
