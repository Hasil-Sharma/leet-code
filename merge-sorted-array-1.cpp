//https://www.lintcode.com/problem/merge-sorted-array/description

class Solution {
public:
    /*
     * @param A: sorted integer array A which has m elements, but size of A is m+n
     * @param m: An integer
     * @param B: sorted integer array B which has n elements
     * @param n: An integer
     * @return: nothing
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
        int k = m + n - 1, j = m - 1, i = n - 1;
        
        while(j >= 0 && i >= 0){
            if (A[j] > B[i]){
                A[k] = A[j];
                j--;
            } else {
                A[k] = B[i];
                i--;
            }
            k--;
        }
        
        while(j >= 0) A[k--] = A[j--];
        while(i >= 0) A[k--] = B[i--];
    }
};
