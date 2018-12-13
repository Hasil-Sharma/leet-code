// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size(), lb = 0, ub = n - 1;
        k = n - k;
        
        while(true){
            int p = nums[ub], i = lb - 1, j = lb;
            
            while(j <= ub){
                if (p >= nums[j])
                    swap(nums[++i], nums[j]);
                j++;
            }
            
            if (i == k) return nums[k];
            else if (i > k) ub = i - 1;
            else lb = i + 1;
            
        }
    }
};
