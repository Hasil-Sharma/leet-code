// https://leetcode.com/problems/knight-probability-in-chessboard/description/

#define mp(A, B) make_pair(A, B)
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<double> vl;
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
typedef unordered_map<int, vi> umvi;
typedef unordered_map<int, vl> umvl;
typedef set<int> si;
vpii steps = {{-1, -2}, {-2, -1}, {1, -2}, {2, -1}, {-1, 2}, {-2, 1}, {1, 2}, {2, 1}};
class Solution {
public:
    int getKey(int r, int c){
        return r*26 + c;
    }
    double knightProbability(int N, int K, int r, int c) {
        unordered_map<int, vl> dp;
        auto n = helper(N, K, 0, r, c, dp);
        return n / pow(8.0, K);
    }
    
    double helper(int N, int K, int k, int r, int c, umvl& dp){
        int key = getKey(r, c);
        
        if (r < 0 || c < 0 || c >= N || r >= N)
            return 0; // in case of invalid move
        else if (k == K)
            return 1;
        
        if (!dp.count(key))
            dp[key] = vl(K, 0);
        else if (dp[key][k] != 0) 
            return dp[key][k];
    
        
        for (auto step : steps){
            int rr = r + step.first, cc = c + step.second;
            dp[key][k] += helper(N, K, k + 1, rr, cc, dp);
        }
        
        return dp[key][k];
    }
};
