// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1, n = nums.size();
        
        if (n == 0 || n == 1) return n;
        
        while(j < n){
            while(j < n && nums[i] >= nums[j])
                j++;
            if (j == n) break;
            swap(nums[++i], nums[j++]);
        }
        
        return i+1;
    }
};
