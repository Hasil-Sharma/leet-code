//https://leetcode.com/problems/max-consecutive-ones/description/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, temp = 0;
        
        for(auto num: nums){
            temp += num;
            ans = (temp > ans) ? temp : ans;
            if (num == 0) temp = 0;
        }
        
        return ans;
    }
};
