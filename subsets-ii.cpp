// https://leetcode.com/problems/subsets-ii/description/

class Solution {
public:
    
    vector<int> temp;
    vector<vector<int>> ans;
    
    void helper(vector<int>& nums, int i){
        ans.push_back(temp);
        for(int j = i; j < nums.size(); j++){
            if (j > i && nums[j] == nums[j-1]) continue;
            temp.push_back(nums[j]);
            helper(nums, j + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        helper(nums, 0);
        return ans;
    }
};
