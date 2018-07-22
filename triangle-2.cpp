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
        int h = triangle.size(), i, j;
        vi prev(h, 0), curr(h, 0);
        
        ff(i, 0, h){
            int size = triangle[i].size();
            ff(j, 0, size){
                curr[j] = triangle[i][j];
                if (j < size - 1 && j > 0)
                    curr[j] += min(prev[j], prev[j - 1]);
                else if (j < size - 1)
                    curr[j] += prev[j];
                else 
                    curr[j] += prev[j-1];
            }
            swap(curr, prev);
        }
        
        return *min_element(prev.begin(), prev.end());
    }
    
};
