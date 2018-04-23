// https://leetcode.com/problems/third-maximum-number/description/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long int max1 = LONG_MIN, max2 = LONG_MIN, max3 = LONG_MIN;
        bool flag = false;
        // max1 < max2 < max3;
        
        for(int n : nums){
            if (n > max3){
                max1 = max2;
                max2 = max3;
                max3 = n;
            } else if (n > max2 && n != max3){
                max1 = max2;
                max2 = n;
            } else if (n > max1 && n != max2 && n != max3 ){
                max1 = n;
            }
        }
        
        return (max1 != LONG_MIN) ? max1 : max3;
    }
};
