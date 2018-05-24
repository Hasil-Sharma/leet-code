// https://leetcode.com/problems/subarray-sum-equals-k/description/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> countHash;
        unordered_map<int, int> :: iterator itr;
        int ans = 0, runningCount = 0;
        countHash[0] = 1; // case when runningCount == k
        for(auto &num : nums){
            runningCount += num;
            if ((itr = countHash.find(runningCount - k)) != countHash.end())
                ans += itr->second;
            countHash[runningCount] += 1;
        }
        
        return ans;
    }
};
