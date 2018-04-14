// https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) ans.push_back(abs(nums[i]));
            else nums[index] *= -1;
        }
        return ans;
    }
};
