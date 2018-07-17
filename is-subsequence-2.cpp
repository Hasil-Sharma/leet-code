// https://leetcode.com/problems/is-subsequence/description/

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
typedef unordered_map<int, int> mpii;
vpii steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        unordered_map<char, set<int>> prep;
        
        for(int i = 0; i < t.length(); i++)
            prep[t[i]].insert(i);
        
        int prev = -1;
        for(char c : s){
            auto itr = prep[c].upper_bound(prev);
            if (itr == prep[c].end()) return false;
            prev = *itr;
        }
        
        return true;
    }
};
