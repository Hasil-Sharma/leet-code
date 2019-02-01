// https://leetcode.com/problems/next-permutation/description/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = findLastIncreasing(nums), j = findSmallestGreater(nums, i);
        if (i >= 0)
        swap(nums[i], nums[j]);
        reverse(nums, i+1);
    }
    
    int findLastIncreasing(vector<int>& nums){
        int i = -1;
        for(int j = 0; j < nums.size() - 1; j++)
            if (nums[j] < nums[j+1])
                i = j;
        
        return i;
    }
    
    int findSmallestGreater(vector<int>& nums, int i){
        int prev = nums[i+1], k = i + 1;
        for(int j = i + 1; j < nums.size(); j++)
            if (prev >= nums[j] && nums[j] > nums[i]){
                prev = nums[j];
                k = j;
            }
        return k;
    }
    
    void reverse(vector<int>& nums, int i){
        int j = nums.size() - 1;
        
        while(i < j)
            swap(nums[i++], nums[j--]);
    }
};
