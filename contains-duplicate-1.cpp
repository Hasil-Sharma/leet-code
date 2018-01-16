// https://leetcode.com/problems/contains-duplicate/description/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> hash_table;
        int ans = false;
        for(int i = 0; i < nums.size() && !ans; i++){
            auto itr = hash_table.find(nums[i]);
            if (itr != hash_table.end())
                ans = true;
            else hash_table[nums[i]] = true;
        }
        return ans;
    }
};
