// https://leetcode.com/problems/find-all-duplicates-in-an-array/submissions/1

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            int index = (nums[i] - 1) % n;
            nums[index] += n;
        }
        
        for(int i = 0; i < n; i++){
            if ((nums[i] / n == 2 && nums[i] % n != 0) || nums[i] / n == 3){
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
