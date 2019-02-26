// https://leetcode.com/problems/remove-invalid-parentheses/description/

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
    vector<string> removeInvalidParentheses(string s) {
        queue<string> q;
        bool flag = true;
        vs ans;
        unordered_set<string> seen;
        q.push(s);
        
        while(!q.empty()){
            s = q.front(); 
            q.pop();
            
            if (seen.count(s)) continue;
            
            seen.insert(s);
            
            if (flag && !isValid(s)) {
                int n = s.length();
                for(int i = 0; i < n; i++){
                    if (s[i] == '(' || s[i] == ')'){
                        q.push(s.substr(0, i) + s.substr(i + 1));
                    }
                }
            } else {
                flag = false;
                if (isValid(s)) ans.push_back(s);
            }
        }
        
        return ans;
        
    }
    
     bool isValid(string& s){
         int c = 0;
         for(char cc : s){
             if (cc == '(') c++;
             else if (cc == ')') c--;
             
             if (c < 0) return false;
         }
         return c == 0;
     }
};
