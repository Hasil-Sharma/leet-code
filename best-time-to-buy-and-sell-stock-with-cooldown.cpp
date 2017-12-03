// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int buy = 0, sell = 1, cool = 2, skip = 3;
    int helper(vector<int>& prices, int index, int prev_op, vector<vector<vector<int>>>& dp, int item_count){
        if (index == prices.size()) return 0;
        else if (dp[index][prev_op][item_count] != INT_MIN) return dp[index][prev_op][item_count];
        
        if (prev_op == buy){
            dp[index][prev_op][item_count] = max(this->helper(prices, index + 1, sell, dp, item_count - 1) + prices[index],
                                                this->helper(prices, index + 1, skip, dp, item_count));
        } else if (prev_op == sell){
            dp[index][prev_op][item_count] = this->helper(prices, index + 1, cool, dp, item_count);
        } else if (prev_op == cool){
            dp[index][prev_op][item_count] = max(this->helper(prices, index + 1, buy, dp, item_count + 1) - prices[index],
                                                this->helper(prices, index + 1, skip, dp, item_count));
        } else if (prev_op = skip){
            if(item_count == 0){
                dp[index][prev_op][item_count] = max(this->helper(prices, index + 1, buy, dp, item_count + 1) - prices[index],
                                                    this->helper(prices, index + 1, skip, dp, item_count));
            } else if (item_count == 1){
                dp[index][prev_op][item_count] = max(this->helper(prices, index + 1, sell, dp, item_count - 1) + prices[index],
                                                    this->helper(prices, index + 1, skip, dp, item_count));
            }
        }
        return dp[index][prev_op][item_count];
    }
    int maxProfit(vector<int>& prices) {
        int ans = 0, n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(4, vector<int>(2, INT_MIN)));
        for(int i = 0; i < n; i++){
            ans = max(this->helper(prices, i, buy, dp, 1) - prices[i], ans);
        }
        return ans;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> prices = stringToIntegerVector(line);
        
        int ret = Solution().maxProfit(prices);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
