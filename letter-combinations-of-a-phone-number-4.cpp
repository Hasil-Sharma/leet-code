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
        vs ans;
        unordered_map<char, vc> adjList;
        queue<vc> q;
        
        if (!digits.length()) 
            return ans;
        
        char cc = 'a';
        for(char c = '2'; c <= '9'; c++){
            int count = c == '7' || c == '9' ? 4 : 3;
            while(count--){
                adjList[c].push_back(cc++);
            }
        }
        
        q.push({});
        
        for(int i = 0; i < digits.length(); i++){
            int size = q.size();
            
            for(int j = 0; j < size; j++){
                auto temp = q.front();
                q.pop();
                
                for (char c : adjList[digits[i]]){
                    temp.push_back(c);
                    q.push(temp);
                    temp.pop_back();
                }
            }
        }
        
        while(!q.empty()){
            auto front = q.front();
            ans.push_back(string(front.begin(), front.end()));
            q.pop();
        }
        return ans;
    }
    
};
