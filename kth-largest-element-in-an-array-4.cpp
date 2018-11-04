// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        k = n - k;
        return helper(nums, 0, n - 1, k);
    }
    
    int helper(vector<int>& nums, int s, int e, int k){
        int kk = (rand() % (e - s + 1)) + s;
        swap(nums[e], nums[kk]);
        int i = s - 1, p = nums[e];
        
        for(int j = s; j < e; j++)
            if (nums[j] <= nums[e])
                swap(nums[++i], nums[j]);
        
        swap(nums[++i], nums[e]);
        
        if (i == k) return nums[i];
        else if (i > k) return helper(nums, s, i - 1, k);
        else return helper(nums, i + 1, e, k);
    }
};
