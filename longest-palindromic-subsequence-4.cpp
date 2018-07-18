// https://leetcode.com/problems/longest-palindromic-subsequence/description/

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
vpii steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int m = s.length();
        vi prev(m + 1, 0);
        vi curr(m + 1, 0);
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= m; j++){
                if (s[i - 1] == s[m  - j]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j], curr[j-1]);
            }
            swap(curr, prev);
        }
        
        return prev[m];
    }
};
