// https://leetcode.com/problems/minimum-size-subarray-sum/description/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i = 0, j = 0, ans = INT_MAX, temp = 0;
        while(j < nums.size()){
            temp += nums[j++];
            while(temp >= s){
                ans = min(ans, j - i);
                temp -= nums[i++];
            }
        }
        return ans != INT_MAX ? ans : 0;
    }
};
