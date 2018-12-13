// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        k = n - k;
        
        return helper(nums, k, 0, n - 1);
    }
    
    int helper(vector<int>& nums, int k , int s, int e){
        int p = nums[e], i = s - 1, j = s;
        
        // partition the array - elements <= nums[e] on left and elements > nums[e] on the right

        while(j <= e){
            if (p >= nums[j])
                swap(nums[++i], nums[j]);
            j++;
        }
        
        if (i == k) return nums[k];
        else if (i > k) return helper(nums, k, s, i-1);
        else return helper(nums, k, i+1, e);
    }
};
