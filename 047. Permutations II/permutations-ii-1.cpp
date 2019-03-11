// https://leetcode.com/problems/permutations-ii/description/
class Solution {
public:

    void helper(set<vector<int>>& answer, vector<int>& nums, int n){
        // exchange n with all the n + 1, n + 2, ... , nums.size() - 1
        
        answer.insert(nums);
        for(int i = n; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                swap(nums[i], nums[j]);
                helper(answer, nums, i + 1);
                swap(nums[i], nums[j]);
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> answer;
        helper(answer, nums, 0);
        return vector<vector<int>>(answer.begin(), answer.end());
    }
};
