// https://leetcode.com/problems/product-of-array-except-self/description/

#define mp(A, B) make_pair(A, B)
#define ff(i, m, n) for(i = m; i < n; i++)
#define ffr(i, m, n) for(i = m; i >= n; i--)
#define ss(v) sort(v.begin(), v.end())
typedef pair<int, int> pii;
typedef vector<int> vi;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), i, runProd = 1;
        vi ans(n, 1);
        ff(i, 0, n)
            ans[i] = (i > 0 ? ans[i-1] : 1) * nums[i];
        
        ffr(i, n - 1, 0){
            ans[i] = (i > 0 ? ans[i-1] : 1) * runProd;
            runProd *= nums[i];
        }
        return ans;
    }
};
