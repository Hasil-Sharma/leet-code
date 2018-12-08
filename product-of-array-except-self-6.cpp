// https://leetcode.com/problems/product-of-array-except-self/description/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), prod = 1;
        vector<int> res(n, 1);
        
        res[0] = nums[0];
        
        for(int i = 1; i < n; i++)
            res[i] = nums[i] * res[i-1];
        
        for(int i = n - 1; i >= 0; i--){
            res[i] = prod * ( i > 0 ? res[i-1] : 1);
            prod *= nums[i];
        }
        
        return res;
    }
};
