// https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/

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
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        vi curr(n + 1, 0), prev(n + 1);
        int ans = 0;
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                curr[j] = (A[i - 1] == B[j - 1]) ? prev[j-1] + 1 : 0;
                ans = max(ans, curr[j]);
            }
            swap(curr, prev);
        }
        
        return ans;
    }
};
