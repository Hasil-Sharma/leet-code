// https://leetcode.com/problems/rotate-array/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> back = nums;
        int n = nums.size(), i = n - k, j = 0;
        
        while(j < n){
            nums[j++] = back[i % n];
            i++;
        }
    }
};
