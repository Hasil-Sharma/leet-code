// https://leetcode.com/problems/word-ladder/description/

#define mp(A, B) make_pair(A, B)
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef stack<int> stki;
typedef queue<int> qi;
typedef queue<string> qs;
typedef deque<int> dqi;
typedef unordered_map<int, int> mpii;
vpii steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    bool count_common(string u, string v){
        int diff = 0;
        for(int i = 0; i < u.length(); i++)
            diff += (u[i] == v[i]) ? 0 : 1;
        return diff == 1;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> vertices;
        unordered_map<string, vs> adjList;
        
        for(string word: wordList)
            vertices[word] = INT_MAX;
        
        vertices[beginWord] = INT_MAX;
        
        for(auto kv1 : vertices){
            for(auto kv2: vertices){
                if (kv1.first == kv2.first) continue;
                else if (count_common(kv1.first, kv2.first))
                adjList[kv1.first].push_back(kv2.first);
            }
        }
        
        qs q;
        q.push(beginWord);
        vertices[beginWord] = 1;
        while(!q.empty()){
            string start = q.front();
            q.pop();
            
            for(string c : adjList[start]){
                if (vertices[c] > vertices[start] + 1){
                    vertices[c] = vertices[start] + 1;
                    if (c == endWord) return vertices[c];
                    q.push(c);
                }
            }
        }
        
        return vertices[endWord] != INT_MAX ? vertices[endWord] : 0;
    }
};
