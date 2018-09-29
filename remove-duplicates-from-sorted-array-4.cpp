// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, j = 1, n = nums.size();
        
        if (n == 0 || n == 1) return n;
        
        while(i < n){
            if (nums[i] != nums[i-1])
                nums[j++] = nums[i];
            i++;
        }
        
        return j;
    }
};
