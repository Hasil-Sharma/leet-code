// https://leetcode.com/problems/two-sum/description/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> ump;
        int i = 0;
        for(auto num : nums){
            if (ump.count(target - num)) return {ump[target - num], i};
            ump[num] = i++;
        }
    }
};
