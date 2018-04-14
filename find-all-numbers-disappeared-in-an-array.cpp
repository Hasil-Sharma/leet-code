// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            int index = abs(nums[i]) - 1; // correct index position of nums[i]
            nums[index] = -1*abs(nums[index]);
        }
        
        for(int i = 0; i < n; i++){
            if (nums[i] > 0)
                ans.push_back(i + 1);
        }
        return ans;
    }
};
