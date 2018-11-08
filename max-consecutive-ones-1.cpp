// https://leetcode.com/problems/max-consecutive-ones/description/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, temp = 0;
        
        for(int num : nums){
            temp += num;
            if (num == 0){
                ans = max(ans, temp);
                temp = 0;
            }
        }
        
        ans = max(ans, temp);
        return ans;
    }
};
