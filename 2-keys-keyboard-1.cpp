// https://leetcode.com/problems/2-keys-keyboard/description/

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

class Solution {
public:
    int minSteps(int n) {
        queue<pair<int, pii>> q;
        if (n == 1) return 0;
        
        q.push(mp(1, mp(1, 1)));
        int len, buffer, ans;
        
        while(true){
            len = q.front().second.first;
            buffer = q.front().second.second;
            ans = q.front().first;
            q.pop();
            if (len == n) return ans;
            if (len + buffer <= n) // pruning very important !
            q.push(mp(ans + 1, mp(len + buffer, buffer))); // paste
            
            if (len != buffer)
                q.push(mp(ans + 1, mp(len, len))); // copy;
        }
    }
};
