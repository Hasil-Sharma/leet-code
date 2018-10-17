// https://leetcode.com/problems/product-of-array-except-self/description/

typedef vector<int> vi;
#define ff(i, m, n) for(i = m; i < n; i++)
#define ffr(i, m, n) for(i = m; i >= n; i--)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), i, runProd = 1;
        vi ans(n, 1);
        
        ff(i, 0, n)
            ans[i] = (i > 0 ? ans[i-1] : 1) * nums[i];
        
        ffr(i, n-1, 0){
            ans[i] = (i > 0 ? ans[i-1] : 1) * runProd;
            runProd = runProd * nums[i];
        }
        
        return ans;
    }
};
