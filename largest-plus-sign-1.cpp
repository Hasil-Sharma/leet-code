// https://leetcode.com/problems/largest-plus-sign/description/

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
typedef queue<pair<int, int>> qpii;
typedef unordered_map<int, int> umpii;
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
    int minVal(int a, int b, int c, int d){
        return min(min(a, b), min(c, d));
    }
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        usi mineSet;
        for(auto& mine : mines)
            mineSet.insert(mine[0]*501 + mine[1]);
        vvi down(N, vi(N, 0));
        vvi right(N, vi(N, 0));
        vi up(N, 0);
        int ans = 0, rightSum = 0;
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                int key = i * 501 + j;
                if (mineSet.count(key)) continue;
                
                down[i][j] = i > 0 ? down[i-1][j] + 1 : 1;
                right[i][j] = j > 0 ? right[i][j-1] + 1 : 1;
            }
        }
        
        for(int i = N - 1; i >= 0; i--){
            rightSum = 0;
            for(int j = N - 1; j >= 0; j--){
                int key = i * 501 + j;
                if (mineSet.count(key)){
                    rightSum = 0;
                    up[j] = 0;
                    continue;
                }
                ans = max(ans, minVal(++up[j], down[i][j], right[i][j], ++rightSum));
                
            }
        }
        
        return ans;
    }
};
