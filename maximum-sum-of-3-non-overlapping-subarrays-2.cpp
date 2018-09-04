// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/description/

typedef vector<int> vi;
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vi w;
        getWindowSum(nums, w, k);
        
        vi left, right;
        getLeftIndices(w, left);
        getRightIndices(w, right);
        
        vi ans = {-1, -1, -1};
        
        for(int b = k; b < w.size() - k; b++){
            int a = left[b - k], c = right[b + k];
            if (ans[0] == -1 || w[a] + w[b] + w[c] > w[ans[0]] + w[ans[1]] + w[ans[2]])
                ans = {a, b, c};
        }
        
        return ans;
    }
    
    void getWindowSum(vi& nums, vi& w, int k){
        int n = nums.size(), sum = 0;
        
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if (i >= k - 1) {
                w.push_back(sum);
                sum -= nums[i - k + 1];
            }
        }
    }
    
    void getLeftIndices(vi& w, vi& left){
        int best = 0;
        left.resize(w.size());
        for(int i = 0; i < w.size(); i++){
            if (w[best] < w[i]) best = i;
            left[i] = best;
        }
    }
    
    void getRightIndices(vi& w, vi& right){
        int best = w.size() - 1;
        right.resize(w.size());
        for(int i = w.size() - 1; i >= 0; i--){
            if (w[best] <= w[i]) best = i;
            right[i] = best;
        }
    }
};
