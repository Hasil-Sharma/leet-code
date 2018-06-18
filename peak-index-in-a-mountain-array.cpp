// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int low = 0, high = A.size();
        
        while(low < high){
            int mid = (low + high) / 2;
            // avoid mid being 0 ?
            if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) return mid;
            else if (A[mid] > A[mid - 1]) low = mid;
            else high = mid;
        }
    }
};
