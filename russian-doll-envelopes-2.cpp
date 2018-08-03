// https://leetcode.com/problems/russian-doll-envelopes/description/

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
typedef vector<char> vc;
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
        cout << e << ", ";
    cout << endl;
}

bool operator<(pii& p1, pii& p2){
    return p1.first < p2.first && p1.second < p2.second;
}

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size(), ans = envelopes.size() != 0;
        sort(envelopes.begin(), envelopes.end());
        vi dp(n, 1);
        int i,j;
        ff(i, 0, n){
            ff(j, 0, i){
                if (envelopes[j] < envelopes[i]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
};
