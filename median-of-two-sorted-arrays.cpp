// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

class Solution {
public:
    int findKthElement(vector<int>& nums1, vector<int>& nums2, int s1, int e1, int s2, int e2, int k){
        // let nums2 > nums1
        if (e1 - s1 > e2 - s2) return findKthElement(nums2, nums1, s2, e2, s1, e1, k);
        
        // nums1 is empty
        if (s1 == e1) return nums2[s2 + k - 1];
        // kth element is what we need
        if (k == 1) return min(nums1[s1], nums2[s2]);
        
        int i = min(e1 - s1, k/2), j = min(e2 - s2, k/2);
        if (nums1[s1 + i - 1] > nums2[s2 + j - 1]) // j elements in nums2 can be skipped
            return findKthElement(nums1, nums2, s1, e1, s2 + j, e2, k - j);
        else
            return findKthElement(nums1, nums2, s1 + i, e1, s2, e2, k - i);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        int val =  findKthElement(nums1, nums2, 0, nums1.size(), 0, nums2.size(), total / 2 + 1);
        if (total % 2 == 1){
            return val;
        } else {
            return (val + findKthElement(nums1, nums2, 0, nums1.size(), 0, nums2.size(), total / 2 ))/2.0;
        }
    }
};
