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

template <typename T>
void printVec(T const& t){
    for(auto e :  t)
        cout << e << ",";
    cout << endl;
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vs ans;
        vc temp;
        unordered_map<char, vc> mp;
        char c = 'a';
        
        for(char i = '2'; i <= '9'; i++){
            int count = (i == '7' || i == '9') ? 4 : 3;
            while(count--)
                mp[i].push_back(c++);
        }
        
        if (digits.length())
        backtrack(digits, mp, ans, temp, 0);
        
        return ans;
    }
    
private:
    
    void backtrack(string& digits, unordered_map<char, vc>& mp, vs& ans, vc& temp, int idx){
        if (idx == digits.length()){
            string str = string(temp.begin(), temp.end());
            ans.push_back(str);
            return;
        }
        
        for(char c : mp[digits[idx]]){
            temp.push_back(c);
            backtrack(digits, mp, ans, temp, idx+1);
            temp.pop_back();
        }
    }
};
