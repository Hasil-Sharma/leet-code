// https://leetcode.com/problems/product-of-array-except-self/description/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> answer(nums.size());
        answer[0] = nums[0];
        
        for(int i = 1; i < nums.size(); i++)
            answer[i] = answer[i-1] * nums[i];
        
        int runProd = 1, temp;
        
        for(int i = nums.size() - 1; i > 0; i--){
            answer[i] = answer[i-1] * runProd;
            runProd *= nums[i];
        }
        
        answer[0] = runProd;
            
        return answer;
    }
};
