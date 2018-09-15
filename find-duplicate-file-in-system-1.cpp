// https://leetcode.com/problems/find-duplicate-file-in-system/description/

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
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vvs ans;
        unordered_map<string, vs> mp;
        for(auto path: paths)
            helper(path, mp);
        
        for(auto kv : mp)
            if (kv.second.size() > 1)
                ans.push_back(kv.second);
        return ans;
    }
    
    void helper(string path, unordered_map<string, vs>& mp){
        stringstream ss;
        ss << path;
        string dir, file;
        int i = 0;
        
        while(ss >> file){
            if (i == 0){
                dir = file;
                i++;
                continue;
            }
            int s = file.find('('), e = file.find(')');
            mp[file.substr(s + 1, e - s - 1)].push_back(dir + "/" + file.substr(0, s));
        }
    }
};
