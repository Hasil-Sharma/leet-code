// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int count = 1, j = 1, idx = 1;
        
        while(j < n){
            if(nums[j] != nums[j-1]){
                nums[idx++] = nums[j];
                count = 1;
            } else if (count < 2){
                nums[idx++] = nums[j];
                count++;
            }
            j++;
        }
        
        return idx;
    }
};
