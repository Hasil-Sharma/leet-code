// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int l = (m + n + 1) / 2, r = (m + n + 2) / 2;
        if (m == 0 || n == 0){
            if (m == 0) {
                swap(nums1, nums2);
                swap(m, n);
            }
            if (m % 2) return nums1[m / 2];
            return (nums1[m / 2] + nums1[m / 2 - 1]) / 2.0;
        }
        return (getKth(&nums1[0], m, &nums2[0], n, l) + getKth(&nums1[0], m, &nums2[0], n, r)) / 2.0;
    }
    
    int getKth(int nums1[], int m, int nums2[], int n, int k){
        if (m > n)
            return getKth(nums2, n, nums1, m, k);
        if (m == 0)
            return nums2[k - 1];
        if (k == 1)
            return min(nums1[0], nums2[0]);
        
        int i = min(m, k / 2), j = min(n, k / 2);
        
        if (nums1[i - 1] > nums2[j - 1])
            return getKth(nums1, m, nums2 + j, n - j, k - j);
        
        return getKth(nums1 + i, m - i, nums2, n, k - i);
    }
};
