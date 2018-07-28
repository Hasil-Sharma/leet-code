// https://www.lintcode.com/problem/best-time-to-buy-and-sell-stock-with-transaction-fee/description

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
    /**
     * @param prices: a list of integers
     * @param fee: a integer
     * @return: return a integer
     */
    int maxProfit(vector<int> &prices, int fee) {
        // write your code here
        int n = prices.size(), i, sell, buy, tsell, tbuy;
        sell = 0;
        buy = -prices[0];
        ff(i, 2, n+1){
            tsell = max(buy + prices[i-1] - fee, sell);
            tbuy = max(sell - prices[i-1], buy);
            sell = tsell;
            buy = tbuy;
        }

        return sell;
    }
};
