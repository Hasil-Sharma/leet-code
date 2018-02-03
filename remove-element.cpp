// https://leetcode.com/problems/remove-element/description/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size(), j = size - 1;
        for(int i = 0; i < size; i++){
            
            // making sure the last element is not the value we wish to remove
            while(j >= 0 && nums[j] == val){
                j--;
            }
            
            
            if (nums[i] == val && j > i){
                swap(nums[i], nums[j]);
                j--;
            }
        }
        return j + 1;
    }
};
