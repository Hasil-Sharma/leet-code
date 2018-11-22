// https://leetcode.com/problems/frog-jump/

class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> dp;
        int n = stones.size();
        for(auto stone : stones)
            dp[stone] = unordered_set<int>();
        
        dp[0].insert(0);
        
        for(auto stone : stones){
            for(auto k : dp[stone]){
                for(int step = k - 1; step <= k + 1; step++){
                    if (step > 0 && dp.count(stone + step))
                        dp[stone+step].insert(step);
                }
            }
        }
        
        return dp[stones[n-1]].size();
    }
};
