// https://leetcode.com/problems/maximum-average-subarray-i/description/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int running_sum = accumulate(nums.begin(), nums.begin() + k, 0);
        int max_sum = running_sum;
        
        for(int i = 0; i + k < nums.size() ; i++){
            running_sum = running_sum - nums[i] + nums[i+k];
            if(running_sum > max_sum) max_sum = running_sum;
        }
        return max_sum * 1.0 / k;
    }
};
