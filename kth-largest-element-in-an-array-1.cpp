// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

typedef vector<int> vi;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return helper(nums, 0, n - 1, n - k + 1);
    }
    
    int helper(vi& nums, int s, int e, int k){
        int p = partition(nums, s, e);
        if (p == k - 1) return nums[p];
        else if (p > k - 1) return helper(nums, s, p - 1, k);
        return helper(nums, p + 1, e, k);
    }
    
    int partition(vi& nums, int s, int e){
        int randNum = rand()%(e - s + 1) + s;
        swap(nums[randNum], nums[e]);
        int x = nums[e], i = s;
        for(int j = s; j < e; j++){
            if (nums[j] <= x)
                swap(nums[j], nums[i++]);
        }
        swap(nums[i], nums[e]);
        return i;
    }
};
