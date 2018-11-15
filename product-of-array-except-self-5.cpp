// https://leetcode.com/problems/product-of-array-except-self/description/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), i = 0, prevProd = 1;
        vector<int> ans(n, 0);
        
        for(int i = 0; i < n; i++)
            ans[i] = i > 0 ? ans[i-1] * nums[i] : nums[i];
        
        for(int i = n - 1; i >= 0; i--){
            ans[i] = i > 0 ? ans[i - 1] * prevProd : prevProd;
            prevProd *= nums[i];
        }
        
        return ans;
    }
};
