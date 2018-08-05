// https://leetcode.com/problems/merge-sorted-array/description/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1, i = m - 1, j = n - 1;
        while(k >= 0){
            if (i >= 0 && j >= 0){
                nums1[k--] = max(nums1[i], nums2[j]);
                (nums1[i] > nums2[j]) ? i-- : j--;
            } else if (i >= 0){
                nums1[k--] =  nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};
