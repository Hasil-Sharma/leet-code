// https://leetcode.com/problems/3sum-closest/description/

#define ff(i, m, n) for(i = m; i < n; i++)
#define ffr(i, m, n) for(i = m; i >= n; i--)
#define ss(v) sort(v.begin(), v.end())
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int i, j, k, n = nums.size(), ans = n > 2 ? nums[0] + nums[1] + nums[2] : 0;
        ss(nums);
        ff(i,0,n){
            j = i + 1; k = n - 1;
            while(j < k){
                int temp = nums[i] + nums[j] + nums[k];
                if (abs(temp - target) < abs(ans - target))
                    ans = temp;
                if (temp > target) k--;
                else j++;
            }
        }
        return ans;
    }
};
