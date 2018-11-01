// https://leetcode.com/problems/rotate-array/description/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        rr(nums, 0, n-1);
        rr(nums, 0, k-1);
        rr(nums, k, n-1);
    }
    
    void rr(vector<int>& nums, int s, int e){
        while(s < e){
            swap(nums[s++], nums[e--]);
        }
    }
};
