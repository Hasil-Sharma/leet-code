// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        k = n - k;
        // find the element which should be at index k;
        
        return selectK(nums, 0, n - 1, k);
    }
    
    int selectK(vector<int>& nums, int s, int e, int k){
        int kk = (rand() % (e - s + 1) + s);
        swap(nums[kk], nums[e]);
        
        int pivot = nums[e], i = s - 1;
        
        for(int j = s; j < e; j++){
            if (nums[j] <= pivot)
                swap(nums[++i], nums[j]);
        }
        
        swap(nums[++i], nums[e]);
        
        if (i == k) return nums[k];
        else if (i < k) return selectK(nums, i + 1, e, k);
        return selectK(nums, s, i - 1, k);
    }
};
