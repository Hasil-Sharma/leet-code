// https://leetcode.com/problems/course-schedule-ii/description/

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
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vi ans, temp;
        umpiv adjList;
        vi indegree(numCourses, 0);
        for(pii& preq : prerequisites){
            adjList[preq.second].push_back(preq.first);
            indegree[preq.first]++;
        }
        int i, j;
        
        while(ans.size() < numCourses){
            
            ff(j, 0, numCourses)
                if (indegree[j] == 0) 
                    temp.push_back(j);
            
            if (temp.size() == 0) {
                ans.clear();
                return ans;
            }
            
            for(int& ii : temp){
                for(int& c : adjList[ii])
                    indegree[c]--;
                indegree[ii] = -1;
            }
            
            ans.insert(ans.end(), temp.begin(), temp.end());
            temp.clear();
        }
        return ans;
    }
    
};
