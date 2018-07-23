// https://leetcode.com/problems/triangle/description/

#define mp(A, B) make_pair(A, B)
#define ff(i, m, n) for(i = m; i < n; i++)
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
typedef deque<int> dqi;
typedef queue<pair<int, int>> qpii;
typedef unordered_map<int, int> umpii;
typedef set<int> si;
typedef unordered_set<int> usi;
vpii steps = {{1, 0}, {1,1}};

template <typename T>
void printVec(T const& t){
    for(auto e :  t)
        cout << e << ",";
    cout << endl;
}

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int h = triangle.size(), i, j, prev1, prev2, size, ans = INT_MAX;
        vi curr(h, 0);
        
        ff(i, 0, h){
            size = triangle[i].size();
            prev1 = prev2 = ans = INT_MAX;
            ff(j, 0, size){
                prev2 = prev1;
                prev1 = curr[j];
                if (j > 0 && j < size - 1)
                    curr[j] = triangle[i][j] + min(prev1, prev2);
                else if (j > 0)
                    curr[j] = triangle[i][j] + prev2;
                else curr[j] = triangle[i][j] + prev1;
                ans = min(ans, curr[j]);
            }
            
        }
        
        return ans;
    }
    
};
