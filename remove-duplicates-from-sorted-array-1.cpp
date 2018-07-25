// https://www.lintcode.com/problem/remove-duplicates-from-sorted-array/description

class Solution {
public:
    /*
     * @param nums: An ineger array
     * @return: An integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        int i = 0, j = 0;
        // all the elements before i are unique and sorted
        // j is the index of next candidate item
        while(j < nums.size()){
            if (i > 0 && nums[i] <= nums[i-1]){
                // nums[i] is at the wrong location
                if (nums[j] > nums[i-1]){
                    // current j can be swapped
                    swap(nums[i], nums[j]);
                    i++;
                }
                j++;
            } else {
                i++;
                j++;
            }
        }
        return i;
    }
};
