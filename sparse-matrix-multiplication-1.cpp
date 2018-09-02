// https://leetcode.com/problems/sparse-matrix-multiplication/description/

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
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), n = m ? A[0].size() : 0, p = n ? B[0].size() : 0;
        
        if (!m || !n || !p) return vvi();
        
        unordered_map<int, umpii> sparseA, sparseB;
        
        vecToSparse(A, sparseA);
        vecToSparse(B, sparseB);
        
        vvi ans(m, vi(p, 0));
        
        for(auto t1: sparseA){
            int row = t1.first;
            for(auto t2 : t1.second){
                int col = t2.first, val = t2.second;
                if (!sparseB.count(col))
                    continue;
                for(auto t3 : sparseB[col])
                    ans[row][t3.first] += val * t3.second; 
            }
        }
        return ans;
    }
    
    void vecToSparse(vvi& A, unordered_map<int, umpii>& m){
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < A[0].size(); j++){
                if (A[i][j])
                    m[i][j] = A[i][j];
            }
        }
    }
};
