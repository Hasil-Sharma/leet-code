// https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/description/
class Solution {
public:
    // finding the number of 5s in the m! count of 2s is always greater
    long getTrailingZeros(long m){
        long ans = 0L;
        for(; m > 0; m /= 5)
            ans += m/5;
        return ans;
    }
    int preimageSizeFZF(int K) {
        
        // since the number of zeroes is always increasing runnning binary search
        // x! has atleast x/5 zeroes and K is the maximum number of zeroes
        // f(x!) >= x/5 and f(x!) = K. Therefore, x <= 5(K + 1)
        for(long l = 0, r = 5L * (K  + 1); l <= r ; ){
            long m = l + (r - l)/2;
            long k = getTrailingZeros(m);
            if (k > K) r = m - 1;
            else if (k < K) l = m + 1;
            else return 5;
        }
        
        return 0;
    }
};
