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
        int n = nums.size(), i;
        vi a(n, 1), b(n, 1), ans(n, 1);
        ff(i, 0, n){
            a[i] = (i > 0 ? a[i-1] : 1) * nums[i];
            b[n - i - 1] = (i > 0 ? b[n-i] : 1) * nums[n - i - 1];
        }
        
        ff(i, 0, n)
            ans[i] = (i > 0 ? a[i-1] : 1) * (i + 1 < n ? b[i+1] : 1);
        return ans;
    }
};
