// https://www.lintcode.com/problem/letter-combinations-of-a-phone-number/description

#define mp(A, B) make_pair(A, B)
#define ff(i, m, n) for(i = m; i < n; i++)
#define ffr(i, m, n) for(i = m; i >= n; i--)
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
    /**
     * @param digits: A digital string
     * @return: all posible letter combinations
     */
    vector<string> letterCombinations(string &digits) {
        // write your code here
        unordered_map<char, vc> adjList;
        char start = 'a', i;
        ff(i, '2', '9' + 1){
            int c = i == '9' || i == '7' ? 4 : 3;
            int j;
            ff(j, 0, c)
                adjList[i].push_back(start++);
        }
        
        vs ans;
        if (digits.length())
        dfs(digits, adjList, ans, "", 0);
        return ans;
    }
    
    void dfs(string& digits, unordered_map<char, vc> adjList, vs& ans, string t, int idx){
        if (idx == digits.length()) {
            ans.push_back(t);
            return;
        }
        
        for(char c : adjList[digits[idx]])
            dfs(digits, adjList, ans, t + c, idx + 1);
    }
};
