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
vpii steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, vc> numToChar;
        char d = 'a';
        
        for(char c = '2'; c <= '9'; c++){
            int count = 3 + (c == '7' || c == '9');
            while (count--)
                numToChar[c].push_back(d++);
        }
        
        vs ans;
        if (digits.size())
            generate(digits, ans, numToChar);
        return ans;
    }
    
    void generate(string& digits, vs& ans, unordered_map<char, vc>& numToChar){
        queue<vc> q;
        q.push({});
        int idx = 0;
        
        while(idx < digits.size()){
            int size = q.size();
            while(size--){
                vc temp = q.front();
                q.pop();
                for(char c : numToChar[digits[idx]]){
                    temp.push_back(c);
                    q.push(temp);
                    temp.pop_back();
                }
            }
            idx++;
        }
        
        while(!q.empty()){
            vc temp = q.front();
            q.pop();
            ans.push_back(string(temp.begin(), temp.end()));
        }
    }
};
