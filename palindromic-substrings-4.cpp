// https://leetcode.com/problems/palindromic-substrings/

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
    int countSubstrings(string s) {
        int n = s.length(), ans = n, i;        
        
        ff(i, 1, n){
            ans += helper(i - 1, i, s);
            ans += helper(i - 1, i + 1, s);
        }
        return ans;
    }
    
    int helper(int l, int h, string& s){
        int count = 0, n = s.length();
        while(l >= 0 && h < n && s[l--] == s[h++]){
            count++;
        }
        return count;
    }
};
