// https://leetcode.com/problems/pacific-atlantic-water-flow/description/

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
typedef deque<int> dqi;
typedef unordered_map<int, int> mpii;
vpii steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vpii answer;
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        
        if (m == 0 || n == 0) 
            return answer;
        
        vvi mask(m, vi(n, -1));
        queue<pii> q;
        for(int M = 0; M < m; M++){
            for(int N = 0; N < n; N++){
                if (mask[M][N] != -1) 
                    continue;
                q.push(mp(M, N));
                while(!q.empty()){
                    int i = q.front().first, j = q.front().second;
                    q.pop();
                    int preval = mask[i][j];
                    if (mask[i][j] == -1) mask[i][j] = 0;
                    if (i == 0 || j == 0) mask[i][j] |= 1;
                    if (i == m - 1 || j == n - 1) mask[i][j] |= 2;

                    for(pii& step : steps){
                        int ii = i + step.first, jj = j + step.second;
                        if (ii >= 0 && jj >= 0 && ii < m && jj < n && matrix[ii][jj] <= matrix[i][j]){
                            if (mask[ii][jj] != -1)
                                mask[i][j] |= mask[ii][jj];
                        }
                    }

                    if (mask[i][j] != preval) {
                        q.push(mp(i,j));
                        for(pii& step : steps){
                            int ii = i + step.first, jj = j + step.second;
                            // water can either flow from or flow into ... thus check for all the neighbors again
                            if (ii >= 0 && jj >= 0 && ii < m && jj < n){
                                q.push(mp(ii,jj));
                            }
                        }
                        if (mask[i][j] == 3) 
                            answer.push_back(mp(i,j));
                    }
                }
            }
        }
        
        return answer;
    }
};
