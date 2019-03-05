
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
typedef unordered_set<string> uss;
vpii steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
template <typename T>
void printVec(T const& t){
    for(auto e :  t)
        cout << e << ",";
    cout << endl;
}
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vvs ans;
        uss dictSet(wordList.begin(), wordList.end());
        unordered_map<string, vs> adjList;
        unordered_map<string, string> prevString;
        int n;
        dictSet.insert(beginWord);
        
        if (!dictSet.count(endWord)) 
            return ans;
        
        for(auto word: dictSet){
            string orig = word;
            for(int i = 0; i < word.length(); i++){
                char prev = word[i];
                for(char c = 'a'; c <= 'z'; c++){
                    if (c == prev) 
                        continue;
                    word[i] = c;
                    if (dictSet.count(word))
                        adjList[orig].push_back(word);
                }
                word[i] = prev;
            }
        }
    
        queue<vs> qq;
        qq.push({beginWord});
        dictSet.erase(beginWord);
        
        while(!qq.empty() && dictSet.count(endWord)){
            n = qq.size();
            
            while(n--){
                auto path = qq.front();
                auto str = path.back();
                qq.pop();
                for(auto child : adjList[str]){
                    if (dictSet.count(child)) {
                        path.push_back(child);
                        qq.push(path);
                        path.pop_back();
                    }
                }
            }
            
            n = qq.size();
            
            while(n--){
                auto path = qq.front();
                auto str = path.back();
                qq.pop();
                dictSet.erase(str);
                qq.push(path);
            }
        }
        
        while(!qq.empty()){
            auto path = qq.front();
            qq.pop();
            if (path.back() == endWord)
                ans.push_back(path);
        }
        return ans;
    }
};
