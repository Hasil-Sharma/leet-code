// https://leetcode.com/problems/subarray-product-less-than-k/description/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start = 0, end = 0, ans = 0;
        long product = 1l;
        
        while(end < nums.size()){
            // define end and find the start which will satisfy !
            product *= nums[end];
            while(start <= end && product >= k){
                product /= nums[start++];
            }
            ans += (end - start + 1);
            end++;
        }
        
        return ans;
    }
};
