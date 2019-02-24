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
            ss(v);
            adjList[itr.first] = v;
        }
        
        ans.push_back("JFK");
        dfs("JFK", adjList, i, ans, tickets.size());
        return ans;
    }
    
    
    void dfs(string p, unordered_map<string, vs>& adjList, int &count, vs& ans, int num){
        if (!adjList.count(p)) return;
        
        int n = adjList[p].size();
        for(int i = 0; i < n; i++){
            auto aa = adjList[p][i];
            adjList[p].erase(adjList[p].begin() + i);
            
            ans.push_back(aa);
            count++;
            
            dfs(aa, adjList, count, ans, num);
            
            if (count == num) return;
            
            adjList[p].insert(adjList[p].begin() + i, aa);
            ans.pop_back();
            count--;
        }
    }
};
