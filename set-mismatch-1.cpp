// https://leetcode.com/problems/set-mismatch/description/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int missing, repeated, idx;
        for(int &num : nums){
            if (nums[abs(num) - 1] < 0) repeated = abs(num);
            else nums[abs(num) - 1] *= -1;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] > 0) missing = i + 1;
        }
        
        return {repeated, missing};
    }
};
