// https://leetcode.com/problems/word-ladder/description/

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

int operator-(string& s1, string& s2){
    int n = s1.length(), diff = 0;
    for(int i = 0; i < n; i++)
        diff += s1[i] != s2[i];
    return diff;
}
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> visited;
        int ans = 0, count = 0, temp;
        for(string& word: wordList){
            count += word == endWord;
        }
        if (!count) return ans;
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        
        while(!q.empty()){
            beginWord = q.front().first; temp = q.front().second;
            q.pop();
            if (visited.count(beginWord)) continue;
            visited.insert(beginWord);
            if (beginWord == endWord) {
                ans = temp;
                break;
            }
            
            for(string& word: wordList){
                if (word - beginWord == 1)
                    q.push({word, temp + 1});
            }
        }
        
        return ans ;
    }
};
