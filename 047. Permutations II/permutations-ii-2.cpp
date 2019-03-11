// https://leetcode.com/problems/permutations-ii/description/

class Solution {
public:
    
    void helper(vector<int> nums, int size, vector<vector<int>>& ans){
        if (size == nums.size() - 1){
            ans.push_back(nums);
            return;
        }
        
        for(int i = size; i < nums.size(); i++){
            if (i != size && (nums[i] == nums[size]))
                continue;
            swap(nums[size], nums[i]);
            helper(nums, size + 1, ans);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        helper(nums, 0, ans);
        return ans;
    }
};
