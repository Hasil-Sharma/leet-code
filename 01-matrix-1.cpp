// https://leetcode.com/problems/01-matrix/description/

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
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int maxval = 100000;
        vvi answer(m, vi(n, maxval));
        queue<pii> q;        
        q.push(mp(0,0));
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int i = front.first, j = front.second;
            int preval = answer[i][j];
            
            for(pii step : steps){
                int ii = i + step.first, jj = j + step.second;
                if(ii >= 0 && jj >= 0 && ii < m && jj < n){
                    answer[i][j] = min(answer[ii][jj] + 1, answer[i][j]);
                }
            }
            
            answer[i][j] = matrix[i][j] == 0 ? 0 : answer[i][j];
            
            if (answer[i][j] == preval && preval != maxval)
                continue;
            
            for(pii step : steps){
                int ii = i + step.first, jj = j + step.second;
                if(ii >= 0 && jj >= 0 && ii < m && jj < n){
                    q.push(mp(ii, jj));
                }
            }
            
        }
        
        return answer;
    }
};
