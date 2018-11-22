// https://leetcode.com/problems/frog-jump/

class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_set<int> stones_hash(stones.begin(), stones.end());
        unordered_map<int,  unordered_set<int>> dp;
        int n = stones.size();        
        helper(stones_hash, dp, 0, 1, stones[n-1]);
        return dp.count(stones[n - 1]) ? true : false;
    }
    
    
    void helper(unordered_set<int>& sh, unordered_map<int, unordered_set<int>>& dp, int nn, int k, int target){
        int next = nn + k;
        if (!sh.count(next) || target < next || next < 0) return;
        
        if (dp.count(next) && dp[next].count(k)) return;
        
        dp[next].insert(k);
        
        helper(sh, dp, next, k - 1, target);
        helper(sh, dp, next, k, target);
        helper(sh, dp, next, k + 1, target);
        
    }
};
