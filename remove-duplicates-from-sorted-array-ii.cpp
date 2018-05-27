// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, j = 1, count = 1;
        // i is the index of last element made part of vector
        // j is the index of current iterating element in the vector
        while(j < nums.size()){
            if(nums[i-1] == nums[j]){
                // in case the last element in new sequence is same the current iterating element
                if (++count == 2){
                    nums[i++] = nums[j];
                }
                j++;
            } else {
                nums[i++] = nums[j++];
                count = 1;
            }
        }
        // handling the case of empty array
        return nums.size() ? i : 0;
    }
};
