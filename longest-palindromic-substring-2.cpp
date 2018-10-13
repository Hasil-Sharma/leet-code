// https://leetcode.com/problems/longest-palindromic-substring/description/

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
    string longestPalindrome(string s) {
        int n = s.length();
        int start = 0, maxLen = 1, i, k, j;
        
        ff(i, 1, n){
            int low = i - 1, high = i;
            helper(low, high, n, start, maxLen, s);
            
            low = i - 1, high = i + 1;
            helper(low, high, n, start, maxLen, s);
        }
        return s.substr(start, maxLen);
    }
    
    void helper(int l, int h, int n, int& start, int& maxLen, string& s){
        while(l >= 0 && h < n && s[l] == s[h]){
            if (h - l + 1 > maxLen){
                start = l;
                maxLen = h - l + 1;
            }
            
            h++;
            l--;
        }
    }
};
