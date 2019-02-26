// https://leetcode.com/problems/word-ladder/description/

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

int operator-(string& w1, string& w2){
    int count = 0, len = w1.length();
    for(int i = 0; i < len; i++)
        count += (w1[i] == w2[i] ? 0 : 1);
    return count;
}

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        umpiv adjList;
        wordList.push_back(beginWord);
        int eLabel = -1, i, j, n = wordList.size(), sLabel = n - 1, label, ans = 0;
        vb visit(n, false);
        queue<pii> q;
        
        ff(i, 0, n){
            eLabel = (eLabel == -1 && wordList[i] == endWord) ? i : eLabel;
            ff(j, 0, n){
                if (wordList[i] - wordList[j] == 1)
                    adjList[i].push_back(j);
            }
        }
        
        if (eLabel == -1) return 0;
        
        q.push({sLabel, 0});
        while(!q.empty()){
            label = q.front().first; ans = q.front().second;
            q.pop();
            visit[label] = true;
            if (label == eLabel) return ans + 1;
            for(int& c : adjList[label]) {
                if (!visit[c])
                    q.push({c, ans + 1});
            }
        }
        
        return ans;
    }
};
