// https://leetcode.com/problems/product-of-array-except-self/description/

typedef vector<int> vi;
#define ff(i, m, n) for(i = m; i < n; i++)
#define ffr(i, m, n) for(i = m; i >= n; i--)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), i;
        vi a(n, 1), b(n, 1), ans(n, 1);
        
        ff(i, 0, n){
            a[i] = (i > 0 ? a[i-1] : 1) * nums[i];
            b[n - i - 1] = (i > 0 ? b[n - i] : 1) * nums[n - i - 1];
        }
        
        ff(i, 0, n){
            ans[i] = (i > 0 ? a[i-1] : 1) * (i < n - 1 ? b[i + 1] : 1);
        }
        
        return ans;
    }
};
