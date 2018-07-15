// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

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
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), ans = 0;
        if (n == 0) return 0;
        vi maxAfter(n);
        
        maxAfter[n-1] = prices.back();
        for(int i = n - 2; i >= 0; i--)
            maxAfter[i] = max(prices[i + 1], maxAfter[i + 1]);
        
        int i = 0;
        for(int price : prices){
            ans = max(ans, maxAfter[i++] - price);
        }
        
        return ans;
    }
};
