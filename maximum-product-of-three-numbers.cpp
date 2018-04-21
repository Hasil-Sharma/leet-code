// https://leetcode.com/problems/maximum-product-of-three-numbers/description/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX;
        
        for(int num : nums){
            
            // max3 < max2 < max1
            if (num > max1){
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if (num > max2){
                max3 = max2;
                max2 = num;
            } else if (num > max3){
                max3 = num;
            } 
            
            // min3 < min2 < min1
            if (num < min3){
                min1 = min2;
                min2 = min3;
                min3 = num;
            } else if (num < min2){
                min1 = min2;
                min2 = num;
            } else if (num < min1){
                min1 = num;
            }   
        }
        
        return max(max1 * max2 * max3, min3 * min2 * max1);
    }
};
