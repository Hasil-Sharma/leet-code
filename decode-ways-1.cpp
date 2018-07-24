// https://leetcode.com/problems/decode-ways/description/

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
    int numDecodings(string s) {
        int n = s.length(), i, prev, curr, temp;
        if (n == 0) return 0;
        prev = 1;
        curr = s[0] != '0';
        ff(i, 2, n + 1){
            int num = (s[i - 1] - '0') + (s[i-2] - '0') * 10;
            temp = curr;
            curr = (s[i-1] != '0' ? curr : 0) + ( num > 9 && num < 27 ? prev : 0);
            prev = temp;
        }
        return curr;
    }
};
