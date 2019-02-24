// https://leetcode.com/problems/reconstruct-itinerary/

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
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vs ans;
        int i = 0;
        
        unordered_map<string, vs> adjList;
        
        for (auto ticket: tickets)
            adjList[get<0>(ticket)].push_back(get<1>(ticket));
        
        for (auto itr : adjList){
            auto v = itr.second;
            sort(v.begin(), v.end(), greater<string>());
            adjList[itr.first] = v;
        }
        
        dfs("JFK", adjList, ans);
        return vector<string>{ans.rbegin(), ans.rend()};
    }
    
    
    void dfs(string p, unordered_map<string, vs>& adjList, vs& ans){
        
        while(adjList[p].size()){
            string aa = adjList[p].back();
            adjList[p].pop_back();
            dfs(aa, adjList, ans);
        }
        
        ans.push_back(p);
    }
};
