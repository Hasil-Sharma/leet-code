// https://leetcode.com/problems/subarray-product-less-than-k/description/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // start with finding the ranges which give the required product
        // remove the common contiguous sequences with the previously found 
        // such sequence
        if (k == 0) return 0;
        int pStart = -1, pEnd = -1, start = 0, end = -1, runProd = 1, ans = 0;
        unsigned long long n;
        for(int i = 0; i < nums.size(); i++){
            runProd *= nums[i];
            if (runProd < k)
                end = i;
            else {
                n = end - start + 1;
                ans += n * (n + 1) / 2;
                if (pEnd >= start) {
                    ans -= (pEnd - start + 1) * (pEnd - start + 2) / 2;
                }
                pStart = start;
                pEnd = end;
                do {
                    runProd /= nums[start++];
                } while (runProd >= k);
                end = i;
            }
        }
        
        n = end - start + 1;
        ans += n * (n + 1) / 2;
        if (pEnd >= start) {
            ans -= (pEnd - start + 1) * (pEnd - start + 2) / 2;
        }
        return ans;
    }
};
