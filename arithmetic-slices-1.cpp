// https://leetcode.com/problems/arithmetic-slices/description/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int ans = 0, n = A.size();
        if (n < 3) return ans;
        int diff = A[1] - A[0], len = 2;
        
        for(int i = 2; i < n; i++){
            int temp = A[i] - A[i-1];
            if (temp == diff) len++;
            else {
                ans += (len - 2) * (len - 1) / 2;
                diff = temp;
                len = 2;
            }
        }
        
        if (len > 2) ans += (len - 2) * (len - 1) / 2;
        return ans;
    }
};
