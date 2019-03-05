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
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vvs ans;
        queue<vs> qq;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.count(endWord) == 0) return ans;
        
        wordSet.insert(beginWord);
        qq.push({beginWord});
        wordSet.erase(beginWord);
        
        while(!qq.empty() && wordSet.count(endWord)){
            int n = qq.size();
            
            while(n--){
                vs path = qq.front();
                qq.pop();
                string last = path.back();
                
                for(int i = 0; i < last.length(); i++){
                    char prev = last[i];
                    for(char c = 'a'; c <= 'z'; c++){
                        if (c == prev) continue;
                        last[i] = c;
                        if (wordSet.count(last)){
                            path.push_back(last);
                            qq.push(path);
                            path.pop_back();
                        }
                    }
                    
                    last[i] = prev;
                }
            }
            
            n = qq.size();
            while(n--){
                vs path = qq.front();
                qq.pop();
                wordSet.erase(path.back());
                if (path.back() == endWord){
                    ans.push_back(path);
                } else {
                    qq.push(path);
                }
            }
            
        }
        
        return ans;
    }
};
