// https://leetcode.com/problems/next-permutation/description/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n - 1, j = n - 1;
        
        while(i > 0 && nums[i - 1] >= nums[i]) 
            i--;
        
        if (i > 0) {
            int p = nums[i - 1];
            while(nums[j] <= p)
                j--;
            swap(nums[i - 1], nums[j]);
        }
        
        j = n - 1;
        while (j > i)
            swap(nums[j--], nums[i++]);
        
    }
};
