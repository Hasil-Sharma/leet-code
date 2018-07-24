// https://www.lintcode.com/problem/move-zeroes/description
class Solution {
public:
    /**
     * @param nums: an integer array
     * @return: nothing
     */
    void moveZeroes(vector<int> &nums) {
        // write your code here
        int nz = 0, zp = 0, i = 0, n = nums.size();
        
        while(nz < n && zp < n){
            while(nums[zp] != 0 && zp < n) zp++;
            nz = zp;
            while(nums[nz] == 0 && nz < n) nz++;
            if (nz >= n) 
                break;
            swap(nums[nz], nums[zp]);
        }
    }
};
