// https://leetcode.com/problems/word-break/description/
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
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vvi dp(n, vi(n + 1, -1));
        return helper(s, wordDict, dp, 0, n);
    }
    
    bool helper(string& s, vs& wordDict, vvi& dp, int start, int len){
        if (len <= 0) return len == 0;
        else if (dp[start][len] == -1) {
            for(string& wd : wordDict){
                if (checkStart(s, wd, start, len) && dp[start][len] != 1){
                    dp[start][len] = helper(s, wordDict, dp, start + wd.length(), len - wd.length()) ? 1 : 0;
                }
                if (endsWith(s, wd, start, len) && dp[start][len] != 1){
                    dp[start][len] = helper(s, wordDict, dp, start, len - wd.length()) ? 1 : 0;
                }
            }
        }
        return dp[start][len] == 1;
    }
    
    bool checkStart(string& s, string& wd, int start, int len){
        if (len < wd.length()) return false;
        for(int i = 0; i < wd.length(); i++){
            if (s[start] != wd[i])
                return false;
            start++;
        }
        
        return true;
    }
    
    bool endsWith(string& s, string& wd, int start, int len){
        if (len < wd.length()) return false;
        
        int end = start + len - 1;
        for(int i = wd.length() - 1; i >= 0; i--){
            if (s[end--] != wd[i])
                return false;
        }

        return true;
    }
};
