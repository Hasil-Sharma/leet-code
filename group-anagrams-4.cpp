// https://leetcode.com/problems/group-anagrams/description/

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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vs> mp;
        vvs ans;
        for(string &str : strs)
            mp[get_hash(str)].push_back(str);
        
        for(auto itr: mp)
            ans.push_back(itr.second);
        
        return ans;
        
    }
    
    string get_hash(string& str){
        vi count(26, 0);
        for(char c : str)
            count[c - 'a']++;
        
        stringstream ss;
        
        for(int i = 0; i < 26; i++)
            if (count[i]) ss << string(count[i], i + 'a');
        
        return ss.str();
    }
};
