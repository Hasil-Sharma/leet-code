//https://leetcode.com/problems/russian-doll-envelopes/description/

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

bool sortbysec(const pii& a, const pii& b){
    return a.second != b.second ? (a.second < b.second) : (a.first <= b.first);
}

bool operator<(const pii& a, const pii& b){
    return a.second < b.second && a.first < b.first;
}

class Solution {
public:
    /*
     * @param envelopes: a number of envelopes with widths and heights
     * @return: the maximum number of envelopes
     */
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        // write your code here
        int n = envelopes.size(), i, ans = 0, k;
        
        sort(envelopes.begin(), envelopes.end(), sortbysec);
        
        vi dp(n, 1);
        ff(i, 0, n){
            ff(k, 0, i)
                if (envelopes[k] < envelopes[i])
                    dp[i] = max(dp[i], 1 + dp[k]);
          ans = max(ans, dp[i]);  
        }
        
        return ans;
    }
};
