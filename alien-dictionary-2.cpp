// https://leetcode.com/problems/alien-dictionary/description/

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
    string alienOrder(vector<string>& words) {
        unordered_map<char, vc> adjList;
        unordered_map<char, int> indegree;
        unordered_set<char> visit;
        string ans = "";
        
        int n = words.size(), i;
        ff(i, 0, n)
            adjListGen(adjList, words, i);
        indegreeGen(adjList, indegree);
        
       ff(i, 0, indegree.size()){
           char c = 0;
           for(auto kv : indegree){
               if (kv.second == 0 && !visit.count(kv.first)){
                   c = kv.first;
                   break;
               }
           }
           
           if (c == 0) return "";
           visit.insert(c);
           
           ans = ans + string(1, c);
           
           for(int v : adjList[c])
               indegree[v]--;
       }
        
        return ans;
    }
    
    void adjListGen(unordered_map<char, vc>& adjList, vs& words, int i){
        int m = words[i].length(), n = words[i+1].length(), j;
        
        ff(j, 0, min(m,n)){
            if (i + 1 < words.size() && words[i][j] != words[i+1][j]){
                adjList[words[i][j]].push_back(words[i+1][j]);
                break;
            }
        }
        
        // adding the characters for both the words
        for(char c : words[i]){
            if(!adjList.count(c))
                adjList[c];
        }
        
        if (i + 1 == words.size() - 1)
        for(char c : words[i+1]){
            if (!adjList.count(c))
                adjList[c];
        }
    }
    
    void indegreeGen(unordered_map<char, vc>& adjList, unordered_map<char, int>& indegree){
        for(auto kv: adjList){
            if (!indegree.count(kv.first)) indegree[kv.first] = 0;
            for(auto v : kv.second)
                indegree[v]++;
        }
    }
};
