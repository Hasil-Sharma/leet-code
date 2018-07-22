// https://leetcode.com/problems/ones-and-zeroes/description/

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



bool operator>=(pii& p, int k){
    return p.first >= k && p.second >= k;
}

class Solution {
public:
    pii str2pii(string& str){
        pii ans = {0, 0};
        for(char c : str){
            if (c == '0') ans.first++;
            else ans.second++;
        }
        return ans;
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        vector<vvi> dp(N+1, vvi(m + 1, vi(n + 1, 0)));
 
        for(int i = 1; i <= N; i++){
            for(int j = 0; j <= m; j++){
                for(int k = 0; k <= n; k++){
                    pii p = str2pii(strs[i - 1]);
                    pii q = {j - p.first, k - p.second};
                    if (q >= 0) dp[i][j][k] = max(dp[i-1][j][k], 1 + dp[i-1][q.first][q.second]);
                    else dp[i][j][k] = dp[i-1][j][k];
                }
            }
        }
        
        return dp[N][m][n];
    }
    
};
