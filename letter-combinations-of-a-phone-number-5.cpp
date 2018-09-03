// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

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

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vs ans;
        unordered_map<char, vc> mapping;
        
        char s = 'a';
        
        for(char i = '2'; i <= '9'; i++){
            int count = i == '7' || i == '9' ? 4 : 3;
            while(count--) mapping[i].push_back(s++);
        }
        
        if (digits.size())
        backtrack(digits, 0, mapping, ans);
        
        return ans;
    }
    
    void backtrack(string& digits, int idx, unordered_map<char, vc>& mapping, vs& ans){
        deque<string> dq;
        dq.push_back("");
        while(idx < digits.size()){
            int size = dq.size();
            for(int i = 0; i < size; i++){
                string s = dq.front();
                dq.pop_front();
                for(char c : mapping[digits[idx]])
                    dq.push_back(s + string(1, c));
            }
            idx++;
        }
        
        ans = {dq.begin(), dq.end()};
    }
};
