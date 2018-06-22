// https://www.lintcode.com/problem/single-number-iv/description

class Solution {
public:
    /**
     * @param nums: The number array
     * @return: Return the single number
     */
    int getSingleNumber(vector<int> &nums) {
        // Write your code here
        int low = 0, high = nums.size() - 1;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            if (nums[mid] == nums[mid - 1]){
                if ((mid - low + 1) % 2 == 1){
                    high = mid - 2;
                } else{
                    low = mid + 1;
                }
            } else if (nums[mid] == nums[mid + 1]){
                if ((high - mid + 1) % 2 == 1){
                    low = mid + 2;
                } else {
                    high = mid - 1;
                }
            } else {
                return nums[mid];
            }
        }

    }
};
