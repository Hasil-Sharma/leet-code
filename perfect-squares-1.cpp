// https://leetcode.com/problems/perfect-squares/description/

#define mp(A, B) make_pair(A, B)
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
    int numSquares(int n) {
        usi ps;
        for(int i = 1; i <= sqrt(n); i++)
            ps.insert(i*i);
        
        vi dp(n + 1, INT_MAX);
        
        for(int i = 1; i <= n; i++){
            if (ps.count(i)) {
                dp[i] = 1;
                continue;
            }
            for(int j = 1; j <= i / 2; j++)
                 dp[i] = min(dp[i], dp[j] + dp[i - j]);
        }
        
        return dp[n];
    }
};
